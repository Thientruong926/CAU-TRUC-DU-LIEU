#include <iostream>
#include <memory>
using namespace std;

class NodeData
{
public:
    virtual void print() const = 0;
    virtual ~NodeData() = default;
};

class StringData : public NodeData
{
    string _strData;

public:
    StringData(string val) : _strData(val) {}
    void print() const override
    {
        cout << "String: " << _strData << endl;
    }
};

class IntData : public NodeData
{
    int _iData;

public:
    IntData(int val) : _iData(val) {}
    void print() const override
    {
        cout << "Int: " << _iData << endl;
    }
};

class FloatData : public NodeData
{
    float _fData;

public:
    FloatData(float val) : _fData(val) {}
    void print() const override
    {
        cout << "Float: " << _fData << endl;
    }
};

class CharData : public NodeData
{
    char _cData;

public:
    CharData(char val) : _cData(val) {}
    void print() const override
    {
        cout << "Char: " << _cData << endl;
    }
};

class LinkedList;
class Node
{
    friend LinkedList;

private:
    shared_ptr<NodeData> _data;
    Node *_pNext;

public:
    Node(shared_ptr<NodeData> data) : _data(data), _pNext(NULL) {}
    void display()
    {
        _data->print();
    }
};

class LinkedList
{
    Node *_pHead;
    Node *_pTail;
    int _iSize;

public:
    LinkedList();
    ~LinkedList();

    void addHead(shared_ptr<NodeData> data);
    void addTail(shared_ptr<NodeData> data);
    void addAfter(Node *node, shared_ptr<NodeData> data);
    Node *search(shared_ptr<NodeData> data);

    Node *searchPre(Node *node);
    void removeHead();
    void removeTail();
    void removeAfter(Node *node);
    void remove(shared_ptr<NodeData> data);

    // void selectionSort();
    int getSize();
    void display();
    void clear();
};

LinkedList::LinkedList()
{
    _pHead = _pTail = NULL;
    _iSize = 0;
}
LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::addHead(shared_ptr<NodeData> data)
{
    Node *newNode = new Node(data);
    if (_pHead == NULL)
    {
        _pHead = _pTail = newNode;
    }
    else
    {
        newNode->_pNext = _pHead;
        _pHead = newNode;
    }
    _iSize++;
}
void LinkedList::addTail(shared_ptr<NodeData> data)
{
    Node *newNode = new Node(data);
    if (_pHead == NULL)
    {
        _pHead = _pTail = newNode;
    }
    else
    {
        _pTail->_pNext = newNode;
        _pTail = newNode;
    }
    _iSize++;
}
void LinkedList::addAfter(Node *node, shared_ptr<NodeData> data)
{
    Node *newNode = new Node(data);
    if (node != NULL)
    {
        newNode->_pNext = node->_pNext;
        node->_pNext = newNode;
        if (node == _pTail)
        {
            _pTail = newNode;
        }
    }
    else
    {
        addHead(data);
    }
    _iSize++;
}
Node *LinkedList::search(shared_ptr<NodeData> data)
{
    Node *pWalker = _pHead;
    while (pWalker->_data != data)
    {
        pWalker = pWalker->_pNext;
    }
    return pWalker;
}

Node *LinkedList::searchPre(Node *node)
{
    Node *pWalker = _pHead;
    if (pWalker == node)
        return NULL;
    while (pWalker != NULL && pWalker->_pNext != node)
    {
        pWalker = pWalker->_pNext;
    }
    return pWalker;
}
void LinkedList::removeHead()
{
    if (_pHead != NULL)
    {
        Node *pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if (_pHead == NULL)
        {
            _pTail = NULL;
        }
        _iSize--;
    }
}
void LinkedList::removeTail()
{
    if (_pHead == NULL)
        return;
    Node *pTemp = _pTail;
    _pTail = searchPre(_pTail);
    delete pTemp;
    if (_pTail != NULL)
    {
        _pTail->_pNext = NULL;
    }
    else
    {
        _pHead = NULL;
    }
    _iSize--;
}
void LinkedList::removeAfter(Node *node)
{
    Node *pTemp;
    if (node != NULL)
    {
        pTemp = node->_pNext;
        if (pTemp != NULL)
        {
            if (pTemp == _pTail)
                _pTail = node;
            node->_pNext = pTemp->_pNext;
            delete pTemp;
        }
    }
    else
        removeHead();
    _iSize--;
}
void LinkedList::remove(shared_ptr<NodeData> data)
{
    Node *pWalker = _pHead, *pTemp = NULL;
    while (pWalker != NULL && pWalker->_data != data)
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
}

// void LinkedList::selectionSort();
int LinkedList::getSize()
{
    return _iSize;
}
void LinkedList::display()
{
    Node *pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
}
void LinkedList::clear()
{
    while (_pHead != NULL)
    {
        removeHead();
    }
}
int main()
{
    LinkedList ll;
    ll.addTail(make_shared<IntData>(10));
    ll.addTail(make_shared<FloatData>(2.5));
    ll.addTail(make_shared<StringData>("Hello World"));
    ll.addTail(make_shared<CharData>('T'));
    ll.display();
}
