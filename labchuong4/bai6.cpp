#include <iostream>
using namespace std;

// Cau a
class Queue;
class HangHoa
{
    // Khai bao lop ban voi lop Queue
    friend Queue;

private:
    // Du lieu cua HangHoa
    string _strMaHang, _strTenHang;
    int _iSoLuong, _iDonGia;
    // Con tro tro den HangHoa ke tiep
    HangHoa *_pNext;

public:
    // Khoi tao HangHoa moi
    HangHoa(string mahang, string tenhang, int soluong, int dongia);
    // HangHoa(const HangHoa &h);
    void display();
};

HangHoa::HangHoa(string mahang, string tenhang, int soluong, int dongia)
{
    _strMaHang = mahang;
    _strTenHang = tenhang;
    _iSoLuong = soluong;
    _iDonGia = dongia;
    _pNext = NULL;
}

// HangHoa::HangHoa(const HangHoa &h)
// {
//     _strMaHang = h._strMaHang;
//     _strTenHang = h._strTenHang;
//     _iSoLuong = h._iSoLuong;
//     _iDonGia = h._iDonGia;
//     _pNext = NULL;
// }

void HangHoa::display()
{
    cout << "Ma hang: " << _strMaHang << endl;
    cout << "Ten hang: " << _strTenHang << endl;
    cout << "So luong: " << _iSoLuong << endl;
    cout << "Don gia: " << _iDonGia << endl;
}

// Cau b
class Queue
{
    // con tro tro den phan tu dau Queue
    HangHoa *_pFront;
    // con tro tro den phan tu cuoi Queue
    HangHoa *_pRear;
    // so phan tu hien tai cua queue
    int _iSize;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enQueue(string mahang, string tenhang, int soluong, int dongia);
    HangHoa deQueue();
    void display();
};

Queue::Queue()
{
    _pFront = _pRear = NULL;
    _iSize = 0;
}

Queue::~Queue()
{
    while (!isEmpty())
        deQueue();
}

bool Queue::isEmpty()
{
    return _pFront == NULL;
}

void Queue::enQueue(string mahang, string tenhang, int soluong, int dongia)
{
    HangHoa *pNew = new HangHoa(mahang, tenhang, soluong, dongia);
    if (pNew == NULL)
    {
        cout << "Khong the them vao Queue";
    }
    else
    {
        if (_pRear == NULL)
        {
            _pFront = _pRear = pNew;
        }
        else
        {
            _pRear->_pNext = pNew;
            _pRear = pNew;
        }
        _iSize++;
    }
}

HangHoa Queue::deQueue()
{
    if (isEmpty())
    {
        cout << "Queue rong!!!" << endl;
        exit(1);
    }
    HangHoa *pTemp = _pFront;
    string mahang = pTemp->_strMaHang, tenhang = pTemp->_strTenHang;
    int soluong = pTemp->_iSoLuong, dongia = pTemp->_iDonGia;
    _pFront = pTemp->_pNext;
    delete pTemp;
    _iSize--;
    if (_pFront == NULL)
        _pRear = NULL;
    return HangHoa(mahang, tenhang, soluong, dongia);
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue rong!" << endl;
    }
    else
    {
        cout << "So luong hang hoa: " << _iSize << endl;
        for (HangHoa *p = _pFront; p != NULL; p = p->_pNext)
            p->display();
    }
}

int main()
{
    Queue queue;
    int iOption = 0;
    do
    {
        system("cls");
        cout << "CHUONG TRINH QUAN LI KHO DON GIAN" << endl;
        cout << "Cac chuc nang quan li kho" << endl;
        cout << "1. Xem tat ca cac hang hoa trong kho" << endl;
        cout << "2. Xem mat hang sap duoc xuat kho" << endl;
        cout << "3. Them mot mat hang vao kho" << endl;
        cout << "4. Xuat mot mat hang ra khoi kho" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Lua chon cua ban la: ";
        cin >> iOption;
        switch (iOption)
        {
        case 1:
            cout << "Tat ca cac hang hoa trong kho: " << endl;
            queue.display();
            system("pause");
            break;
        case 2:
        {
            cout << "Mat hang sap duoc xuat kho: " << endl;
            HangHoa res = queue.deQueue();
            res.display();
            system("pause");
            break;
        }
        case 3:
        {
            cout << "Mat hang can them\n";
            string mahang, tenhang;
            int soluong, dongia;
            cout << "Nhap ma mat hang: ";
            cin >> mahang;
            cin.ignore();
            cout << "Nhap ten mat hang: ";
            getline(cin, tenhang);
            cout << "Nhap so luong: ";
            cin >> soluong;
            cout << "Nhap don gia: ";
            cin >> dongia;
            queue.enQueue(mahang, tenhang, soluong, dongia);
            break;
        }
        case 4:
            queue.deQueue();
            break;
        default:
            break;
        }
    } while (iOption != 0);
    return 0;
}