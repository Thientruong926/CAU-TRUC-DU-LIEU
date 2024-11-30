#include <iostream>
#include <ctype.h>
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
    // Xem gia tri phan tu o dinh Stack
    DataType peek();
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

template <class DataType>
DataType Stack<DataType>::peek()
{
    if (isEmpty())
    {
        cout << "Stack rong!!!" << endl;
        exit;
    }
    return _pTop->_data;
}

int precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    return 3;
}

int main()
{
    // Bieu thuc trung to
    string strTT;
    cout << "Nhap bieu thuc trung to: ";
    cin >> strTT;
    Stack<char> st;
    for (char x : strTT)
    {
        if (x == '(')
            st.push(x);
        else if (isalpha(x) || isdigit(x))
        {
            cout << x;
        }
        else if (x == ')')
        {
            while (st.peek() != '(')
                cout << st.pop();
            st.pop();
        }
        else
        {
            while (!st.isEmpty() && precedence(x) <= precedence(st.peek()))
                cout << st.pop();
            st.push(x);
        }
    }
    while (!st.isEmpty())
        cout << st.pop();
    return 0;
}