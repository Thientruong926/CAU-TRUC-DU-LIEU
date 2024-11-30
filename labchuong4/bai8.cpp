#include <iostream>
using namespace std;

class LinkedListA;
class QueueB;
class LinkedListC;
class SoGhe
{
    friend LinkedListA;

private:
    int _iSoGhe;
    SoGhe *_pNext;

public:
    SoGhe(int soghe);
};
SoGhe::SoGhe(int soghe)
{
    _iSoGhe = soghe;
    _pNext = NULL;
}

class LinkedListA
{
    SoGhe *_pHead;
    SoGhe *_pTail;
    int _iSize;

public:
    LinkedListA();
    ~LinkedListA();
    void clear();
    void removeHead();
    void addTail(int data);
    int getSize();
    void remove(int data);
    SoGhe *search(int data);
};
LinkedListA::LinkedListA()
{
    _pHead = _pTail = NULL;
    _iSize = 0;
}
LinkedListA::~LinkedListA()
{
    clear();
}
void LinkedListA::clear()
{
    while (_pHead != NULL)
    {
        removeHead();
    }
}
void LinkedListA::removeHead()
{
    if (_pHead != NULL)
    {
        SoGhe *pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if (_pHead == NULL)
        {
            _pTail = NULL;
        }
    }
}
void LinkedListA::addTail(int data)
{
    SoGhe *pAdd = new SoGhe(data);
    if (_pHead == NULL)
        _pHead = _pTail = pAdd;
    else
    {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    _iSize++;
}
int LinkedListA::getSize()
{
    return _iSize;
}
void LinkedListA::remove(int data)
{
    SoGhe *pWalker = _pHead, *pTemp = NULL;
    while (pWalker != NULL && pWalker->_iSoGhe != data)
    {
        pTemp = pWalker;
        pWalker = pWalker->_pNext;
    }
    if (pWalker == NULL)
        return;
    if (pTemp != NULL)
    {
        if (pWalker == _pTail)
        {
            _pTail = pTemp;
            _pTail->_pNext = NULL;
        }
        pTemp->_pNext = pWalker->_pNext;
        delete pTemp;
        _iSize--;
    }
    else if (pWalker != NULL && pWalker->_iSoGhe == data)
        removeHead();
}
SoGhe *LinkedListA::search(int data)
{
    SoGhe *pWalker = _pHead;
    while (pWalker != NULL && pWalker->_iSoGhe != data)
        pWalker = pWalker->_pNext;
    return pWalker;
}

class SoThuTu
{
    friend QueueB;

private:
    int _iSoThuTu;
    string _strTen;
    SoThuTu *_pNext;

public:
    SoThuTu(int sothutu, string ten);
};
SoThuTu::SoThuTu(int sothutu, string ten)
{
    _iSoThuTu = sothutu;
    _strTen = ten;
    _pNext = NULL;
}

class QueueB
{
    SoThuTu *_pFront;
    SoThuTu *_pRear;
    int _iSize;
    static int _iSoThuTu;

public:
    QueueB();
    ~QueueB();
    void clear();
    void enQueue(string ten);
    string deQueue();
    int getSize();
};
int QueueB::_iSoThuTu = 0;
QueueB::QueueB()
{
    _pFront = _pRear = NULL;
    _iSize = 0;
}
QueueB::~QueueB()
{
    clear();
}
void QueueB::clear()
{
    SoThuTu *pTemp;
    while (_pFront != NULL)
    {
        pTemp = _pFront;
        _pFront = pTemp->_pNext;
        delete pTemp;
    }
    _iSize = 0;
    _pRear = NULL;
}
void QueueB::enQueue(string ten)
{
    SoThuTu *pAdd = new SoThuTu(++_iSoThuTu, ten);
    if (_pRear == NULL)
        _pFront = _pRear = pAdd;
    else
    {
        _pRear->_pNext = pAdd;
        _pRear = pAdd;
    }
    _iSize++;
}
string QueueB::deQueue()
{
    SoThuTu *pTemp = _pFront;
    string ten = pTemp->_strTen;
    _pFront = pTemp->_pNext;
    delete pTemp;
    if (_pFront == NULL)
        _pRear = NULL;
    _iSize--;
    return ten;
}
int QueueB::getSize()
{
    return _iSize;
}

class ThongTin
{
    friend LinkedListC;

private:
    int _iSoGhe;
    string _strTen;
    ThongTin *_pNext;

public:
    ThongTin(int soghe, string hoten);
};
ThongTin::ThongTin(int soghe, string hoten)
{
    _iSoGhe = soghe;
    _strTen = hoten;
    _pNext = NULL;
}

class LinkedListC
{
    ThongTin *_pHead;
    ThongTin *_pTail;
    int _iSize;

public:
    LinkedListC();
    ~LinkedListC();
    void clear();
    void removeHead();
    void addTail(int soghe, string ten);
    ThongTin *search(int data);
    void remove(int data);
    void display();
};
LinkedListC::LinkedListC()
{
    _pHead = _pTail = NULL;
    _iSize = 0;
}
LinkedListC::~LinkedListC()
{
    clear();
}
void LinkedListC::clear()
{
    while (_pHead != NULL)
    {
        removeHead();
    }
}
void LinkedListC::removeHead()
{
    if (_pHead != NULL)
    {
        ThongTin *pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if (_pHead == NULL)
        {
            _pTail = NULL;
        }
        _iSize--;
    }
}
void LinkedListC::addTail(int soghe, string ten)
{
    ThongTin *pAdd = new ThongTin(soghe, ten);
    if (_pHead == NULL)
        _pHead = _pTail = pAdd;
    else
    {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    _iSize++;
}
ThongTin *LinkedListC::search(int data)
{
    ThongTin *pWalker = _pHead;
    while (pWalker != NULL && pWalker->_iSoGhe != data)
        pWalker = pWalker->_pNext;
    return pWalker;
}
void LinkedListC::remove(int data)
{
    ThongTin *pWalker = _pHead, *pTemp = NULL;
    while (pWalker != NULL && pWalker->_iSoGhe != data)
    {
        pTemp = pWalker;
        pWalker = pWalker->_pNext;
    }
    if (pWalker == NULL)
        return;
    if (pTemp != NULL)
    {
        if (pWalker == _pTail)
        {
            _pTail = pTemp;
            _pTail->_pNext = NULL;
        }
        pTemp->_pNext = pWalker->_pNext;
        delete pTemp;
        _iSize--;
    }
    else if (pWalker != NULL && pWalker->_iSoGhe == data)
        removeHead();
}
void LinkedListC::display()
{
    ThongTin *pWalker = _pHead;
    if (_iSize == 0)
        cout << "Khong co khach hang nao mua ve" << endl;
    else
    {
        cout << "So luong khach hang mua ve: " << _iSize << endl;
        while (pWalker != NULL)
        {
            cout << "Ten khach hang: " << pWalker->_strTen << "/ So ghe: " << pWalker->_iSoGhe << endl;
            pWalker = pWalker->_pNext;
        }
    }
}

int main()
{
    LinkedListA A;
    QueueB B;
    LinkedListC C;
    for (int i = 1; i < 101; i++)
    {
        A.addTail(i);
    }
    int iOption = 0;
    do
    {
        system("cls");
        cout << "CHUONG TRINH MO PHONG QUY TRINH DAT VE XEM PHIM" << endl;
        cout << "Cac chuc nang cua chuong trinh:" << endl;
        cout << "1. Lay so xep hang" << endl;
        cout << "2. Mua ve" << endl;
        cout << "3. Huy ve" << endl;
        cout << "4. Hien thi" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Lua chon cua ban la: ";
        cin >> iOption;
        switch (iOption)
        {
        case 1:
        {
            string ten;
            cout << "Nhap ten khach hang: ";
            cin.ignore();
            getline(cin, ten);
            B.enQueue(ten);
            break;
        }
        case 2:
        {
            if (!A.getSize())
                cout << "Khong con ghe trong\n";
            else if (!B.getSize())
                cout << "Khong co thong tin khach hang\n";
            else
            {
                // cout << "yes" << endl;
                string strTenKhachHang = B.deQueue();
                int soghe;
                cout << "Nhap so ghe khach chon: ";
                cin >> soghe;
                if (A.search(soghe) != NULL)
                {
                    C.addTail(soghe, strTenKhachHang);
                    A.remove(soghe);
                    cout << "Mua ve thanh cong" << endl;
                }
                else
                    cout << "Khong tim thay so ghe" << endl;
            }
            system("pause");
            break;
        }
        case 3:
        {
            cout << "Nhap so ghe can huy: ";
            int soghe;
            cin >> soghe;
            if (C.search(soghe) != NULL)
            {
                C.remove(soghe);
                A.addTail(soghe);
                cout << "Huy ve thanh cong\n";
            }
            else
                cout << "Khong tim thay so ghe\n";
            system("pause");
            break;
        }
        case 4:
            C.display();
            system("pause");
            break;
        default:
            break;
        }
    } while (iOption != 0);
    return 0;
}