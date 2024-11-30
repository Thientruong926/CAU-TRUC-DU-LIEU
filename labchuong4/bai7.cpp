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
    // Huy stack
    ~Stack();
    // Kiem tra xem Stack co rong khong
    bool isEmpty();
    // Them vao Stack phan tu co gia tri data
    void push(DataType data);
    // Xoa va tra ve phan tu tren dinh Stack
    DataType pop();
    // Hien thi toan bo Stack
    void display();
    // Xoa toan bo Stack
    void clear();
};

template <class DataType>
Stack<DataType>::Stack()
{
    _pTop = NULL;
    _iSize = 0;
}

template <class DataType>
Stack<DataType>::~Stack()
{
    while (!isEmpty())
    {
        clear();
    }
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
void Stack<DataType>::display()
{
    if (isEmpty())
        cout << "Stack rong!" << endl;
    else
    {
        cout << "So phan tu cua Stack: " << _iSize << endl;
        for (Node<DataType> *p = _pTop; p != NULL; p = p->_pNext)
            p->display();
    }
}

template <class DataType>
void Stack<DataType>::clear()
{
    Node<DataType> *pTemp;
    while (_pTop != NULL)
    {
        pTemp = _pTop;
        _pTop = pTemp->_pNext;
        delete pTemp;
    }
    _iSize = 0;
}

int main()
{
    Stack<int> iStack;
    iStack.push(2);
    iStack.push(3);
    iStack.push(4);
    iStack.display();
    cout << endl;

    Stack<double> dStack;
    dStack.push(2.4);
    dStack.push(3.7);
    dStack.push(4.6);
    dStack.display();
    cout << endl;

    Stack<char> cStack;
    cStack.push('d');
    cStack.push('E');
    cStack.push('+');
    cStack.display();
    cout << endl;

    Stack<string> strStack;
    strStack.push("abc");
    strStack.push("doe");
    strStack.push("lamo lmoa");
    strStack.display();
}