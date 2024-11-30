#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
class LinkedList;
class Movie
{
    friend LinkedList;

private:
    string _strTenPhim, _strTheLoai, _strTenDD, _strTenDVNamC, _strTenDVNuC;
    int _iNamSanXuat;
    Movie *_pNext;

public:
    void setTheLoai(string x)
    {
        if (x != "hinh su" && x != "tinh cam" && x != "hai")
        {
            cerr << "The loai phim khong dung";
            exit(1);
        }
        _strTheLoai = x;
    }
    Movie(string tenphim, string theloai, string tendd, string tendvnamc, string tendvnuc, int namsanxuat)
    {
        _strTenPhim = tenphim;
        setTheLoai(theloai);
        _strTenDD = tendd;
        _strTenDVNamC = tendvnamc;
        _strTenDVNuC = tendvnuc;
        _iNamSanXuat = namsanxuat;
        _pNext = NULL;
    }
    void display()
    {
        cout << "Ten phim: " << _strTenPhim << endl;
        cout << "The loai: " << _strTheLoai << endl;
        cout << "Ten dao dien: " << _strTenDD << endl;
        cout << "Ten dien vien nam chinh: " << _strTenDVNamC << endl;
        cout << "Ten dien vien nu chinh: " << _strTenDVNuC << endl;
        cout << "Nam san xuat: " << _iNamSanXuat << endl;
        cout << endl;
    }
    void fileDisplay(ofstream &ofs)
    {
        ofs << "Ten phim: " << _strTenPhim << endl;
        ofs << "The loai: " << _strTheLoai << endl;
        ofs << "Ten dao dien: " << _strTenDD << endl;
        ofs << "Ten dien vien nam chinh: " << _strTenDVNamC << endl;
        ofs << "Ten dien vien nu chinh: " << _strTenDVNuC << endl;
        ofs << "Nam san xuat: " << _iNamSanXuat << endl;
        ofs << endl;
    }
    Movie *getpNext()
    {
        return _pNext;
    }
};

class LinkedList
{
    Movie *_pHead;
    Movie *_pTail;
    int _iSize;

public:
    LinkedList();
    void addTail(string tenphim, string theloai, string tendd, string tendvnamc, string tendvnuc, int namsanxuat);
    void display();
    Movie *search(string x);
    void capnhat(string x, string theloai);
    void fileDisplay();
    void boPhimDVDong(string TenDV);
    void thongKe();
    void selectionSort();
    int getSize();
    Movie *getHead();
};
LinkedList::LinkedList()
{
    _pHead = _pTail = NULL;
    _iSize = 0;
}

void LinkedList::addTail(string tenphim, string theloai, string tendd, string tendvnamc, string tendvnuc, int namsanxuat)
{
    Movie *newMovie = new Movie(tenphim, theloai, tendd, tendvnamc, tendvnuc, namsanxuat);
    if (_pHead == NULL)
    {
        _pHead = _pTail = newMovie;
    }
    else
    {
        _pTail->_pNext = newMovie;
        _pTail = newMovie;
    }
    _iSize++;
}

void LinkedList::display()
{
    Movie *pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
}

Movie *LinkedList::search(string x)
{
    Movie *pWalker = _pHead;
    while (pWalker != NULL && pWalker->_strTenPhim != x)
    {
        pWalker = pWalker->_pNext;
    }
    return pWalker;
}

void LinkedList::capnhat(string x, string theloai)
{
    Movie *node = search(x);
    if (node != NULL)
    {
        node->setTheLoai(theloai);
    }
    else
    {
        cout << "Khong tim thay ten phim" << endl;
    }
}

void LinkedList::fileDisplay()
{
    ofstream ofs;
    ofs.open("Input.txt", ios::out | ios::app);
    Movie *pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->fileDisplay(ofs);
        pWalker = pWalker->_pNext;
    }
    ofs.close();
}

void LinkedList::boPhimDVDong(string TenDV)
{
    ofstream ofs;
    ofs.open(TenDV);
    ofs << "Cac bo phim nam dien vien tung dong:" << endl;
    Movie *pWalker = _pHead;
    while (pWalker != NULL)
    {
        if (pWalker->_strTenDVNamC == TenDV)
        {
            ofs << pWalker->_strTenPhim << endl;
        }
        pWalker = pWalker->_pNext;
    }
    ofs.close();
}

// Thong ke tong so luong bo phim va thong tin cua cac bo phim cho moi dao dien
void LinkedList::thongKe()
{
    map<string, int> mp;
    Movie *pWalker = _pHead;
    while (pWalker != NULL)
    {
        mp[pWalker->_strTenDD]++;
        pWalker = pWalker->_pNext;
    }
    for (auto &pair : mp)
    {
        ofstream ofs;
        ofs.open(pair.first);
        ofs << "So luong bo phim cua dao dien " << pair.first << ": " << pair.second << endl;
        ofs.close();
    }
    Movie *pWalker2 = _pHead;
    while (pWalker2 != NULL)
    {
        ofstream ofs;
        ofs.open(pWalker2->_strTenDD, ios::app);
        pWalker2->fileDisplay(ofs);
        ofs.close();
        pWalker2 = pWalker2->_pNext;
    }
}

void LinkedList::selectionSort()
{
    for (Movie *p = _pHead; p->_pNext != NULL; p = p->_pNext)
    {
        Movie *max = p;
        for (Movie *q = p->_pNext; q != NULL; q = q->_pNext)
        {
            if (max->_iNamSanXuat < q->_iNamSanXuat)
            {
                max = q;
            }
        }
        swap(p->_iNamSanXuat, max->_iNamSanXuat);
        swap(p->_strTenDD, max->_strTenDD);
        swap(p->_strTenDVNamC, max->_strTenDVNamC);
        swap(p->_strTenDVNuC, max->_strTenDVNuC);
        swap(p->_strTenPhim, max->_strTenPhim);
        swap(p->_strTheLoai, max->_strTheLoai);
    }
}

int LinkedList::getSize()
{
    return _iSize;
}
Movie *LinkedList::getHead()
{
    return _pHead;
}
int main()
{
    // Cau a
    LinkedList ll;
    ifstream ifs;
    ifs.open("Input.txt", ios::in);
    int n;
    ifs >> n;
    ifs.ignore();
    for (int i = 0; i < n; i++)
    {
        string tenphim, theloai, tendd, tendvnamc, tendvnuc, temp;
        int namsanxuat;
        string s;
        getline(ifs, s);
        stringstream ss(s);
        getline(ss, tenphim, '#');
        getline(ss, theloai, '#');
        getline(ss, tendd, '#');
        getline(ss, tendvnamc, '#');
        getline(ss, tendvnuc, '#');
        getline(ss, temp, '#');
        namsanxuat = stoi(temp);
        ll.addTail(tenphim, theloai, tendd, tendvnamc, tendvnuc, namsanxuat);
    }
    ifs.close();

    // Cau b
    string x, theloai;
    cout << "Nhap ten phim can cap nhat: ";
    cin >> x;
    cin.ignore();
    cout << "Nhap the loai can cap nhat: ";
    getline(cin, theloai);
    ll.capnhat(x, theloai);
    ll.fileDisplay();

    // Cau c
    cout << "So luong phim: " << n << endl;
    ll.display();

    // Cau d
    string tenNDV;
    cout << "Nhap ten nam dien vien: ";
    getline(cin, tenNDV);
    ll.boPhimDVDong(tenNDV);

    // Cau e
    ll.thongKe();

    // Cau f
    ofstream ofs;
    ofs.open("PhimMoi.txt");
    if (ll.getSize() < 3)
    {
        ofs << "Khong du so luong yeu cau";
    }
    else
    {
        ll.selectionSort();
        Movie *pWalker = ll.getHead();
        int a = 3;
        while (a--)
        {
            pWalker->fileDisplay(ofs);
            pWalker = pWalker->getpNext();
        }
    }
}