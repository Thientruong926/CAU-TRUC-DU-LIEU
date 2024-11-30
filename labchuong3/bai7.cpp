#include <iostream>
#include <math.h>
using namespace std;

class LinkedList;
class Node
{
    friend LinkedList;

private:
    int _iHeSo, _iSoMu;
    Node *_pNext;

public:
    Node(int heso, int somu)
    {
        _iHeSo = heso;
        _iSoMu = somu;
        _pNext = NULL;
    }
    void display()
    {
        if (_iHeSo != 0)
        {
            if (_iHeSo != 1 || _iSoMu == 0)
                cout << _iHeSo;
            if (_iSoMu != 0)
            {
                cout << 'x';
                if (_iSoMu != 1)
                    cout << '^' << _iSoMu;
            }
        }
    }
    void daoHam()
    {
        if (_iHeSo != 0)
        {
            if (_iSoMu != 0)
            {
                _iHeSo *= _iSoMu;
                _iSoMu--;
            }
            else
            {
                _iHeSo = 0;
            }
        }
    }
    int value(int x)
    {
        return _iHeSo * (int)pow(x, _iSoMu);
    }
    int getHeSo()
    {
        return _iHeSo;
    }
    int getSoMu()
    {
        return _iSoMu;
    }
    Node *getpNext()
    {
        return _pNext;
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

    void addTail(int heso, int somu);
    void selectionSort();
    void rutGon();
    void removeAfter(Node *node);
    void removeHead();
    void display();
    void clear();
    void daoHam();
    int value(int x);
    Node *getHead();
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

void LinkedList::addTail(int heso, int somu)
{
    Node *newNode = new Node(heso, somu);
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
void LinkedList::selectionSort()
{
    for (Node *p = _pHead; p->_pNext != NULL; p = p->_pNext)
    {
        Node *pTemp = p;
        for (Node *q = p->_pNext; q != NULL; q = q->_pNext)
        {
            if (q->_iSoMu > pTemp->_iSoMu)
                pTemp = q;
        }
        swap(p->_iHeSo, pTemp->_iHeSo);
        swap(p->_iSoMu, pTemp->_iSoMu);
    }
}
void LinkedList::rutGon()
{
    if (_pHead == NULL)
        return;
    selectionSort();
    for (Node *p = _pHead; p != NULL; p = p->_pNext)
    {
        Node *q = p->_pNext;
        while (q != NULL && p->_iSoMu == q->_iSoMu)
        {
            p->_iHeSo += q->_iHeSo;
            removeAfter(p);
            q = p->_pNext;
        }
    }
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
            {
                _pTail = node;
            }
            node->_pNext = pTemp->_pNext;
            delete pTemp;
        }
    }
    else
    {
        removeHead();
    }
    _iSize--;
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

void LinkedList::display()
{
    Node *pWalker = _pHead;
    if (pWalker == NULL)
        return;
    while (pWalker->_pNext != NULL)
    {
        pWalker->display();
        if (pWalker->_pNext->_iHeSo > 0)
        {
            cout << '+';
        }
        pWalker = pWalker->_pNext;
    }
    pWalker->display();
    cout << endl;
}

void LinkedList::clear()
{
    while (_pHead != NULL)
    {
        removeHead();
    }
}

void LinkedList::daoHam()
{
    Node *pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->daoHam();
        pWalker = pWalker->_pNext;
    }
}

int LinkedList::value(int x)
{
    Node *pWalker = _pHead;
    int res = 0;
    while (pWalker != NULL)
    {
        res += pWalker->value(x);
        pWalker = pWalker->_pNext;
    }
    return res;
}

Node *LinkedList::getHead()
{
    return _pHead;
}

LinkedList tong(LinkedList &f1, LinkedList &f2)
{
    LinkedList f3;
    Node *pWalker1 = f1.getHead(), *pWalker2 = f2.getHead();
    while (pWalker1 != NULL)
    {
        f3.addTail(pWalker1->getHeSo(), pWalker1->getSoMu());
        pWalker1 = pWalker1->getpNext();
    }
    while (pWalker2 != NULL)
    {
        f3.addTail(pWalker2->getHeSo(), pWalker2->getSoMu());
        pWalker2 = pWalker2->getpNext();
    }
    f3.rutGon();
    return f3;
}

LinkedList tich(LinkedList &f1, LinkedList &f2)
{
    LinkedList f3;
    Node *pWalker1 = f1.getHead();
    while (pWalker1 != NULL)
    {
        Node *pWalker2 = f2.getHead();
        while (pWalker2 != NULL)
        {
            int newHeSo = pWalker1->getHeSo() * pWalker2->getHeSo();
            int newSoMu = pWalker1->getSoMu() + pWalker2->getSoMu();
            if (newHeSo != 0)
            {
                f3.addTail(newHeSo, newSoMu);
            }
            pWalker2 = pWalker2->getpNext();
        }
        pWalker1 = pWalker1->getpNext();
    }
    f3.rutGon();
    return f3;
}
int main()
{
    // Cau a
    LinkedList f1, f2;
    int n1, n2;
    cout << "Nhap so luong don thuc cua f1: ";
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int heso, somu;
        cout << "Nhap he so va so mu cua f1 thu " << i + 1 << ": ";
        cin >> heso >> somu;
        f1.addTail(heso, somu);
    }
    cout << "Nhap so luong don thuc cua f2: ";
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int heso, somu;
        cout << "Nhap he so va so mu cua f2 thu " << i + 1 << ": ";
        cin >> heso >> somu;
        f2.addTail(heso, somu);
    }
    f1.rutGon();
    f2.rutGon();

    // Cau b
    cout << "Da thuc f1: ";
    f1.display();
    cout << "Da thuc f2: ";
    f2.display();

    // Cau c
    f1.daoHam();
    f2.daoHam();
    cout << "Dao ham f1: ";
    f1.display();
    cout << "Dao ham f2: ";
    f2.display();

    // Cau d
    int x;
    cout << "Nhap gia tri cua x: ";
    cin >> x;
    cout << "Gia tri cua da thuc f1: " << f1.value(x) << endl;
    cout << "Gia tri cua da thuc f2: " << f2.value(x) << endl;

    // Cau e
    LinkedList f3 = tong(f1, f2);
    cout << "Tong hai da thuc: ";
    f3.display();

    // Cau f
    f3 = tich(f1, f2);
    cout << "Tich hai da thuc: ";
    f3.display();
    return 0;
}