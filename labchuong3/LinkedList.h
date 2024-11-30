#pragma once
#include <iostream>
#include <cstddef>
#include <math.h>
#include <unistd.h>

using namespace std;

template <class DataType>
class LinkedList;
template <class DataType>
class Node
{
    // Khai bao lop ban voi LinkedList
    friend LinkedList<DataType>;

private:
    // Thanh phan du lieu cua Node
    DataType _data;
    // Con tro tro den Node ke tiep
    Node *_pNext;

public:
    // Khoi tao Node moi co du lieu la data
    Node(DataType data);
    Node(const Node<DataType> &a);
    // Hien thi du lieu cua Node
    void display();
    DataType getData();
    void setData(DataType x);
    Node<DataType> *getpNext();
    void setpNext(Node<DataType> *a);
};

/**********************************************************
 *@Description Khoi tao mot Node moi co gia tri la data
 **********************************************************/
template <class DataType>
Node<DataType>::Node(DataType data)
{
    _data = data;
    _pNext = NULL;
}
/**********************************************************
 *@Description Khoi tao sao chep Node
 **********************************************************/
template <class DataType>
Node<DataType>::Node(const Node<DataType> &a)
{
    _data = a._data;
    _pNext = a._pNext;
}

/**********************************************************
 *@Description Hien thi gia tri Node
 **********************************************************/
template <class DataType>
void Node<DataType>::display()
{
    cout << _data << endl;
}

template <class DataType>
DataType Node<DataType>::getData()
{
    return _data;
}

template <class DataType>
Node<DataType> *Node<DataType>::getpNext()
{
    return _pNext;
}

template <class DataType>
void Node<DataType>::setData(DataType x)
{
    _data = x;
}

template <class DataType>
void Node<DataType>::setpNext(Node<DataType> *a)
{
    _pNext = a;
}

template <class DataType>
class LinkedList
{
    Node<DataType> *_pHead;
    Node<DataType> *_pTail;
    int _iSize;

public:
    LinkedList();
    LinkedList(Node<DataType> *pHead, Node<DataType> *pTail, int iSize);
    LinkedList(const LinkedList<DataType> &ll);

    void addHead(DataType data);
    void addTail(DataType data);
    void addAfter(Node<DataType> *node, DataType data);
    Node<DataType> *search(DataType data);

    Node<DataType> *searchPre(Node<DataType> *node);
    void removeHead();
    void removeTail();
    void removeAfter(Node<DataType> *node);
    void remove(DataType data);

    void selectionSort();
    int getSize();
    void display();
    void clear();
    Node<DataType> *getHead();
    Node<DataType> *getTail();
};

/**********************************************************
 *@Description Khoi tao LinkedList khong tham so
 **********************************************************/
template <class DataType>
LinkedList<DataType>::LinkedList()
{
    _pHead = _pTail = NULL;
    _iSize = 0;
}

/**********************************************************
 *@Description Khoi tao LinkedList co tham so
 **********************************************************/
template <class DataType>
LinkedList<DataType>::LinkedList(Node<DataType> *pHead, Node<DataType> *pTail, int iSize)
{
    _pHead = pHead;
    _pTail = pTail;
    _iSize = iSize;
}

/**********************************************************
 *@Description Khoi tao sao chep LinkedList
 **********************************************************/
template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType> &ll)
{
    _pHead = ll._pHead;
    _pTail = ll._pTail;
    _iSize = ll._iSize;
}

template <class DataType>
Node<DataType> *LinkedList<DataType>::getHead()
{
    return _pHead;
}

template <class DataType>
Node<DataType> *LinkedList<DataType>::getTail()
{
    return _pTail;
}

/**********************************************************
 *@Description Xuat toan bo du lieu cua LinkedList
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::display()
{
    Node<DataType> *pWalker = _pHead;
    while (pWalker != NULL)
    {
        pWalker->display();
        pWalker = pWalker->_pNext;
    }
}

/**********************************************************
 *@Description Them mot phan tu vao dau LinkedList
 *@parameter Gia tri cua phan tu can them
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::addHead(DataType data)
{
    Node<DataType> *pAdd = new Node<DataType>(data);
    if (_pHead == NULL)
    {
        _pHead = _pTail = pAdd;
    }
    else
    {
        pAdd->_pNext = _pHead;
        _pHead = pAdd;
    }
    _iSize++;
}

/**********************************************************
 *@Description Them mot phan tu vao cuoi LinkedList
 *@parameter Gia tri cua phan tu can them
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::addTail(DataType data)
{
    Node<DataType> *pAdd = new Node<DataType>(data);
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

/**********************************************************
 *@Description Them mot phan tu vao sau phan tu node trong LinkedList
 *@parameter Phan tu node va gia tri cua phan tu can them
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::addAfter(Node<DataType> *node, DataType data)
{
    Node<DataType> *pAdd = new Node<DataType>(data);
    if (node != NULL)
    {
        pAdd->_pNext = node->_pNext;
        node->_pNext = pAdd;
        if (node == _pTail)
            _pTail = pAdd;
    }
    else
    {
        addHead(data);
    }
    _iSize++;
}

/**********************************************************
 *@Description Tim mot phan tu trong LinkedList khi biet khoa
 *@parameter Gia tri khoa cua phan tu can tim
 *@return Tra ve phan tu duoc tim thay, NULL neu khong tim thay
 **********************************************************/
template <class DataType>
Node<DataType> *LinkedList<DataType>::search(DataType data)
{
    Node<DataType> *p = _pHead;
    while ((p != NULL) && (p->_data != data))
        p = p->_pNext;
    return p;
}

/**********************************************************
 *@Description Tim mot phan tu dung truoc mot phan tu trong LinkedList
 *@parameter Phan tu dung truoc phan tu can tim
 *@return Tra ve phan tu duoc tim thay, NULL neu khong tim thay
 **********************************************************/
template <class DataType>
Node<DataType> *LinkedList<DataType>::searchPre(Node<DataType> *node)
{
    Node<DataType> *p = _pHead;
    if (p == node)
        return NULL;
    while ((p != NULL) && (p->_pNext != node))
        p = p->_pNext;
    return p;
}

/**********************************************************
 *@Description Xoa phan tu o dau LinkedList
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::removeHead()
{
    if (_pHead != NULL)
    {
        Node<DataType> *pTemp = _pHead;
        _pHead = _pHead->_pNext;
        delete pTemp;
        if (_pHead == NULL)
            _pTail = NULL;
        _iSize--;
    }
}

/**********************************************************
 *@Description Xoa phan tu o cuoi LinkedList
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::removeTail()
{
    if (_pHead == NULL)
        return;
    Node<DataType> *pTemp = _pTail;
    _pTail = searchPre(_pTail);
    delete pTemp;
    if (_pTail != NULL)
        _pTail->_pNext = NULL;
    else
        _pHead = NULL;
    _iSize--;
}

/**********************************************************
 *@Description Xoa phan tu o sau phan tu khac trong LinkedList
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::removeAfter(Node<DataType> *node)
{
    Node<DataType> *pTemp;
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
    {
        removeHead();
    }
    _iSize--;
}

/**********************************************************
 *@Description Xoa phan tu co khoa la data trong LinkedList
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::remove(DataType data)
{
    Node<DataType> *pWalker = _pHead, *pTemp = NULL;
    while ((pWalker != NULL) && (pWalker->_data != data))
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

/**********************************************************
 *@Description Xoa toan bo LinkedList
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::clear()
{
    while (_pHead != NULL)
        removeHead();
}

/**********************************************************
 *@Description Sap xep danh sach theo thuat toan Selection Sort
 **********************************************************/
template <class DataType>
void LinkedList<DataType>::selectionSort()
{
    Node<DataType> *pMin; // tro den phan tu co data min
    Node<DataType> *p, *q;
    for (p = _pHead; p->_pNext != NULL; p = p->_pNext)
    {
        pMin = p;
        for (q = p->_pNext; q != NULL; q = q->_pNext)
        {
            if (q->_data < pMin->_data)
                pMin = q;
        }
        swap(pMin->_data, p->_data);
    }
}

/**********************************************************
 *@Description Tra ve so luong phan tu trong LinkedList
 **********************************************************/
template <class DataType>
int LinkedList<DataType>::getSize()
{
    return _iSize;
}
