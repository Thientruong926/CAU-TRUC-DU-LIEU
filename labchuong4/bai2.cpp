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

int main()
{
    Stack<char> st;
    // Xau ngoac
    string xn;
    cout << "Nhap xau ngoac de kiem tra xau ngoac dung: ";
    cin >> xn;
    for (char c : xn)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.isEmpty())
            {
                cout << "Xau ngoac khong dung!";
                return 0;
            }
            else
            {
                char top = st.pop();
                if ((top == '(' && c != ')') || (top == '{' && c != '}') || (top == '[' && c != ']'))
                {
                    cout << "Xau ngoac khong dung!";
                    return 0;
                }
            }
        }
    }
    if (!st.isEmpty())
    {
        cout << "Xau ngoac khong dung!";
    }
    else
    {
        cout << "Xau ngoac dung";
    }
    return 0;
}