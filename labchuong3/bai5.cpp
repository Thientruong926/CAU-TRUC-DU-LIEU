#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

class LinkedList;

class Student
{
    // Khai bao lop ban voi LinkedList
    friend LinkedList;

private:
    // Thanh phan du lieu cua Student
    string _strMaSV, _strHoTen, _strLop;
    chrono::system_clock::time_point ngaySinh;
    float _fDiemTB;
    // Con tro tro den Student ke tiep
    Student *_pNext;

public:
    Student();
    Student(string masv, string hoten, string lop, int nam, int thang, int ngay, float diemtb);
    Student(const Student &h);
    string getMaSV();
    string getHoTen();
    string getLop();
    string getNgaySinh();
    float getDiemTB();
    void setMaSV(string masv);   // rang buoc du lieu
    void setHoTen(string hoten); // rang buoc du lieu
    void setLop(string lop);
    void setNgaySinh(int nam, int thang, int ngay);
    void setDiemTB(float diemtb); // rang buoc du lieu
    void display();
    Student *getpNext();
    void setpNext(Student *a);
    tm timePointToTm(const std::chrono::system_clock::time_point &tp);
    int getYear();
    int getMonth();
    int getDay();
};

Student::Student()
{
    _strMaSV = _strHoTen = _strLop = "";
    ngaySinh = chrono::system_clock::now();
    _fDiemTB = 0;
    _pNext = NULL;
}

Student::Student(string masv, string hoten, string lop, int nam, int thang, int ngay, float diemtb)
{
    setMaSV(masv);
    setHoTen(hoten);
    _strLop = lop;
    setNgaySinh(nam, thang, ngay);
    setDiemTB(diemtb);
    _pNext = NULL;
}

Student::Student(const Student &h)
{
    _strMaSV = h._strMaSV;
    _strHoTen = h._strHoTen;
    _strLop = h._strLop;
    ngaySinh = h.ngaySinh;
    _fDiemTB = h._fDiemTB;
    _pNext = h._pNext;
}

string Student::getMaSV()
{
    return _strMaSV;
}

string Student::getHoTen()
{
    return _strHoTen;
}

string Student::getLop()
{
    return _strLop;
}

string Student::getNgaySinh()
{
    time_t ngaySinhTimeT = chrono::system_clock::to_time_t(ngaySinh);
    ostringstream oss;
    oss << put_time(localtime(&ngaySinhTimeT), "%Y-%m-%d");
    return oss.str();
}

float Student::getDiemTB()
{
    return _fDiemTB;
}

void Student::setMaSV(string masv)
{
    if (masv.length() != 11)
    {
        cerr << "Error: Ma sinh vien phai co dung 11 ky tu!\n";
        exit(0);
    }
    else
        _strMaSV = masv;
}

void Student::setHoTen(string hoten)
{
    if (hoten.find(" ") == string::npos)
    {
        cerr << "Error: Ho ten phai co khoang cach!\n";
        exit(0);
    }
    else
        _strHoTen = hoten;
}

void Student::setLop(string lop)
{
    _strLop = lop;
}

void Student::setNgaySinh(int nam, int thang, int ngay)
{
    tm tm = {};
    tm.tm_year = nam - 1900;
    tm.tm_mon = thang - 1;
    tm.tm_mday = ngay;
    ngaySinh = chrono::system_clock::from_time_t(mktime(&tm));
}

void Student::setDiemTB(float diemtb)
{
    if (diemtb < 0 || diemtb > 10)
    {
        cerr << "Error: Diem trung binh phai co gia tri tu 0 den 10!\n";
        exit(0);
    }
    else
        _fDiemTB = diemtb;
}

void Student::display()
{
    cout << "Ma: " << _strMaSV << endl;
    cout << "Ho ten: " << _strHoTen << endl;
    cout << "Lop: " << _strLop << endl;
    cout << "Ngay sinh: " << getNgaySinh() << endl;
    cout << "Diem trung binh: " << _fDiemTB << endl;
}

Student *Student::getpNext()
{
    return _pNext;
}

void Student::setpNext(Student *a)
{
    _pNext = a;
}

tm Student::timePointToTm(const std::chrono::system_clock::time_point &tp)
{
    time_t timeT = chrono::system_clock::to_time_t(tp);
    tm tmStruct;
    localtime_s(&tmStruct, &timeT);
    return tmStruct;
}

int Student::getYear()
{
    tm tmStruct = timePointToTm(ngaySinh);
    return tmStruct.tm_year + 1900;
}

int Student::getMonth()
{
    tm tmStruct = timePointToTm(ngaySinh);
    return tmStruct.tm_mon + 1;
}

int Student::getDay()
{
    tm tmStruct = timePointToTm(ngaySinh);
    return tmStruct.tm_mday;
}

class LinkedList
{
    Student *_pHead;
    Student *_pTail;
    int _iSize;

public:
    LinkedList();
    LinkedList(Student *pHead, Student *pTail, int iSize);
    LinkedList(const LinkedList &ll);
    ~LinkedList();
    Student *getHead();
    Student *getTail();
    void addTail(string masv, string hoten, string lop, int nam, int thang, int ngay, float diemtb);
    void display();
    Student *search(string masv);
    void swapStudents(Student *s1, Student *s2);
    int getSize();
    void remove(string x);
    void removeHead();
};

LinkedList::LinkedList()
{
    _pHead = _pTail = NULL;
    _iSize = 0;
}

LinkedList::LinkedList(Student *pHead, Student *pTail, int iSize)
{
    _pHead = pHead;
    _pTail = pTail;
    _iSize = iSize;
}

LinkedList::LinkedList(const LinkedList &ll) : _pHead(NULL), _pTail(NULL), _iSize(0)
{
    Student *p = ll._pHead;
    while (p != NULL)
    {
        addTail(p->getMaSV(), p->getHoTen(), p->getLop(), p->getYear(), p->getMonth(), p->getDay(), p->getDiemTB());
        p = p->getpNext();
    }
}

LinkedList::~LinkedList()
{
    Student *p = _pHead;
    while (p != NULL)
    {
        Student *next = p->getpNext();
        delete p;
        p = next;
    }
}

Student *LinkedList::getHead()
{
    return _pHead;
}

Student *LinkedList::getTail()
{
    return _pTail;
}

void LinkedList::addTail(string masv, string hoten, string lop, int nam, int thang, int ngay, float diemtb)
{
    Student *pAdd = new Student(masv, hoten, lop, nam, thang, ngay, diemtb);
    if (_pHead == NULL)
    {
        _pHead = _pTail = pAdd;
    }
    else
    {
        _pTail->_pNext = pAdd;
        _pTail = pAdd;
    }
    _iSize++;
}

void LinkedList::display()
{
    Student *pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
}

LinkedList finddtb(LinkedList &ll)
{
    LinkedList res;
    Student *pWalker = ll.getHead();
    while (pWalker != NULL)
    {
        if (pWalker->getDiemTB() >= 5)
        {
            res.addTail(pWalker->getMaSV(), pWalker->getHoTen(), pWalker->getLop(), pWalker->getYear(), pWalker->getMonth(), pWalker->getDay(), pWalker->getDiemTB());
        }
        pWalker = pWalker->getpNext();
    }
    return res;
}

Student *LinkedList::search(string masv)
{
    Student *p = _pHead;
    while ((p != NULL) && (p->_strMaSV != masv))
        p = p->_pNext;
    return p;
}

void LinkedList::swapStudents(Student *s1, Student *s2)
{
    swap(s1->_strMaSV, s2->_strMaSV);
    swap(s1->_strHoTen, s2->_strHoTen);
    swap(s1->_strLop, s2->_strLop);
    swap(s1->ngaySinh, s2->ngaySinh);
    swap(s1->_fDiemTB, s2->_fDiemTB);
}

void selectionSort(LinkedList &ll)
{
    for (Student *p = ll.getHead(); p != NULL && p->getpNext() != NULL; p = p->getpNext())
    {
        string min = p->getMaSV();
        Student *pmin = p;
        for (Student *q = p->getpNext(); q != NULL; q = q->getpNext())
        {
            if (min > q->getMaSV())
            {
                min = q->getMaSV();
                pmin = q;
            }
        }
        ll.swapStudents(p, pmin);
    }
}

int LinkedList::getSize()
{
    return _iSize;
}

Student *binarySearch(LinkedList &ll, string masv)
{
    int left = 0, right = ll.getSize();
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        Student *midStudent = ll.getHead();
        for (int i = 0; i < mid; i++)
        {
            midStudent = midStudent->getpNext();
        }
        if (midStudent->getMaSV() == masv)
        {
            return midStudent;
        }
        if (midStudent->getMaSV() > masv)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return NULL;
}

void LinkedList::remove(string x)
{
    Student *pWalker = _pHead, *pTemp = NULL;
    while ((pWalker != NULL) && (pWalker->_strMaSV != x))
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
        delete pWalker;
        _iSize--;
    }
    else
    {
        removeHead();
    }
}

void LinkedList::removeHead()
{
    if (_pHead != NULL)
    {
        Student *pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if (_pHead == NULL)
            _pTail = NULL;
        _iSize--;
    }
}

void updateMark(LinkedList &ll, string x, float y)
{
    Student *res = binarySearch(ll, x);
    if (res == NULL)
    {
        cout << "Khong tim thay sinh vien\n";
        return;
    }
    res->setDiemTB(y);
    ll.display();
}

int main()
{
    // Cau a
    LinkedList ll;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string masv, hoten, lop;
        int nam, thang, ngay;
        float diemtb;
        cout << "Ma sinh vien: ";
        cin >> masv;
        cin.ignore();
        cout << "Ho ten: ";
        getline(cin, hoten);
        cout << "Lop: ";
        cin >> lop;
        cout << "Ngay sinh: ";
        cin >> nam >> thang >> ngay;
        cout << "Diem trung binh: ";
        cin >> diemtb;
        ll.addTail(masv, hoten, lop, nam, thang, ngay, diemtb);
    }

    // Cau b
    cout << "THONG TIN SINH VIEN:\n";
    ll.display();

    // Cau c
    LinkedList c = finddtb(ll);
    c.display();

    // Cau d
    cout << "Nhap ma sinh vien can tim tuan tu: ";
    string masv;
    cin >> masv;
    Student *d = ll.search(masv);
    d->display();

    // Cau e
    selectionSort(ll);
    ll.display();

    // Cau f
    cout << "Nhap ma sinh vien can tim nhi phan: ";
    string masv2;
    cin >> masv2;
    Student *res = binarySearch(ll, masv2);
    if (res == NULL)
    {
        cout << "Khong tim thay thong tin sinh vien\n";
    }
    else
    {
        res->display();
    }

    // Cau g
    cout << "Nhap ma sinh vien can xoa: ";
    string x;
    cin >> x;
    ll.remove(x);
    ll.display();

    // Cau h
    cout << "Nhap ma sinh vien can cap nhat diem: ";
    string x2;
    cin >> x2;
    cout << "Nhap diem moi: ";
    float fDiem;
    cin >> fDiem;
    updateMark(ll, x2, fDiem);
}
