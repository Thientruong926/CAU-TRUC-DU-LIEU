#include "LinkedList.h"

LinkedList<int> createLLUsingSub(LinkedList<int> L1, LinkedList<int> L2)
{
    LinkedList<int> res;
    Node<int> *pWalker1 = L1.getHead(), *pWalker2 = L2.getHead();
    while (pWalker1 != NULL)
    {
        res.addTail(pWalker1->getData());
        pWalker1 = pWalker1->getpNext();
    }
    while (pWalker2 != NULL)
    {
        while (res.search(pWalker2->getData()) != NULL)
            res.remove(pWalker2->getData());
        pWalker2 = pWalker2->getpNext();
    }
    return res;
}

void interchangeSortLL(LinkedList<int> &ll)
{
    for (Node<int> *p = ll.getHead(); p->getpNext() != NULL; p = p->getpNext())
    {
        for (Node<int> *q = p->getpNext(); q != NULL; q = q->getpNext())
        {
            if (p->getData() > q->getData())
            {
                int tmp = p->getData();
                p->setData(q->getData());
                q->setData(tmp);
            }
        }
    }
}

LinkedList<int> createLLUsingConnect(LinkedList<int> L1, LinkedList<int> L2)
{
    LinkedList<int> res;
    Node<int> *pWalker1 = L1.getHead(), *pWalker2 = L2.getHead();
    while (pWalker1 != NULL)
    {
        res.addTail(pWalker1->getData());
        pWalker1 = pWalker1->getpNext();
    }
    while (pWalker2 != NULL)
    {
        res.addTail(pWalker2->getData());
        pWalker2 = pWalker2->getpNext();
    }
    return res;
}

void deleteDuplicateElement(LinkedList<int> &ll)
{
    LinkedList<int> res;
    Node<int> *node = ll.getHead();
    while (node != NULL)
    {
        if (res.search(node->getData()) == NULL)
        {
            res.addTail(node->getData());
        }
        node = node->getpNext();
    }
    ll = res;
}
LinkedList<int> createFullLL(LinkedList<int> L1, LinkedList<int> L2)
{
    LinkedList<int> res = createLLUsingConnect(L1, L2);
    deleteDuplicateElement(res);
    return res;
}

LinkedList<int> createLLUsingHop(LinkedList<int> L1, LinkedList<int> L2)
{
    LinkedList<int> sub1 = createLLUsingSub(L1, L2), sub2 = createLLUsingSub(L2, L1);
    return createLLUsingConnect(sub1, sub2);
}

LinkedList<int> createLLUsingGiao(LinkedList<int> L1, LinkedList<int> L2)
{
    return createLLUsingSub(createFullLL(L1, L2), createLLUsingHop(L1, L2));
}

int main()
{
    LinkedList<int> L1, L2, L3;
    int x;
    cout << "Nhap cac phan tu cua danh sach lien ket don L1: ";
    while (cin >> x)
    {
        L1.addTail(x);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap cac phan tu cua danh sach lien ket don L2: ";
    while (cin >> x)
    {
        L2.addTail(x);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Cau a
    L3 = createLLUsingSub(L1, L2);
    interchangeSortLL(L3);
    cout << "Ket qua cua L3 chua tap hop L1 hieu tap hop L2 co thu tu tang dan:\n";
    L3.display();

    // Cau b
    L3 = createLLUsingGiao(L1, L2);
    interchangeSortLL(L3);
    cout << "Ket qua cua L3 chua tap hop L1 giao tap hop L2 co thu tu tang dan:\n";
    L3.display();

    // Cau c
    L3 = createFullLL(L1, L2);
    interchangeSortLL(L3);
    cout << "Ket qua cua L3 chua tap hop L1 hop tap hop L2 co thu tu tang dan:\n";
    L3.display();
    return 0;
}