#include <iostream>
using namespace std;

template <class DataType>
class Stack;
template <class DataType>
class Node
{
    // Khai bao lop ban voi lop Stack
    friend Stack<DataType>;

private:
    // Du lieu cua Node
    DataType _data;
    // Con tro tro den Node ke tiep
    Node *_pNext;

public:
    // Khoi tao Node moi co gia tri la data
    Node(DataType data);
    // Hien thi du lieu cua Node
    void display();
};

template <class DataType>
Node<DataType>::Node(DataType data)
{
    _data = data;
    _pNext = NULL;
}

template <class DataType>
void Node<DataType>::display()
{
    cout << _data << endl;
}

template <class DataType>
class Stack
{
    // Con tro tro toi phan tu dinh Stack
    Node<DataType> *_pTop;
    // So phan tu hien tai cua Stack
    int _iSize;

public:
    // Khoi tao Stack rong
    Stack();
    // Kiem tra xem Stack co rong khong
    bool isEmpty();
    // Them vao Stack phan tu co gia tri data
    void push(DataType data);
    // Xoa va tra ve phan tu tren dinh Stack
    DataType pop();
};

template <class DataType>
Stack<DataType>::Stack()
{
    _pTop = NULL;
    _iSize = 0;
}

template <class DataType>
bool Stack<DataType>::isEmpty()
{
    return _pTop == NULL;
}

template <class DataType>
void Stack<DataType>::push(DataType data)
{
    Node<DataType> *pTemp = new Node(data);
    pTemp->_pNext = _pTop;
    _pTop = pTemp;
    _iSize++;
}

template <class DataType>
DataType Stack<DataType>::pop()
{
    if (isEmpty())
    {
        cout << "Stack rong!!!" << endl;
        exit;
    }
    Node<DataType> *pTemp = _pTop;
    DataType temp = pTemp->_data;
    _pTop = pTemp->_pNext;
    delete pTemp;
    _iSize--;
    return temp;
}

void quickSort(int a[], int left, int right)
{
    Stack<int> st1, st2;
    st1.push(left);
    st2.push(right);
    while (!st1.isEmpty())
    {
        int l = st1.pop(), r = st2.pop();
        if (l >= r)
            continue;
        int x = a[(l + r) / 2];
        int i = l, j = r;
        while (i < j)
        {
            while (a[i] < x)
                i++;
            while (a[j] > x)
                j--;
            if (i <= j)
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if (l < j)
        {
            st1.push(l);
            st2.push(j);
        }
        if (i < r)
        {
            st1.push(i);
            st2.push(r);
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu trong mang can sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}