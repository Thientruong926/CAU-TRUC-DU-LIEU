#include "LinkedList.h"

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
void assign(LinkedList<int> &L1, LinkedList<int> L2)
{
    L1.clear();
    Node<int> *pWalker = L2.getHead();
    while (pWalker != NULL)
    {
        L1.addTail(pWalker->getData());
        pWalker = pWalker->getpNext();
    }
}
LinkedList<int> createSumLL(LinkedList<int> L1, LinkedList<int> L2)
{
    if (L1.getSize() > L2.getSize())
    {
        LinkedList<int> temp;
        assign(temp, L1);
        assign(L1, L2);
        assign(L2, temp);
    }
    while (L1.getSize() < L2.getSize())
        L1.addTail(0);
    LinkedList<int> res;
    Node<int> *pWalker1 = L1.getHead();
    Node<int> *pWalker2 = L2.getHead();
    while (pWalker1 != NULL)
    {
        res.addTail(pWalker1->getData() + pWalker2->getData());
        pWalker1 = pWalker1->getpNext();
        pWalker2 = pWalker2->getpNext();
    }
    return res;
}

bool checkDistinctValue(LinkedList<int> L1, LinkedList<int> L2)
{
    bool f1 = L1.getSize() == createLLUsingSub(L1, L2).getSize();
    bool f2 = L2.getSize() == createLLUsingSub(L2, L1).getSize();
    return f1 && f2;
}

int sumLL(LinkedList<int> L1)
{
    int sum = 0;
    Node<int> *pWalker = L1.getHead();
    while (pWalker != NULL)
    {
        sum += pWalker->getData();
        pWalker = pWalker->getpNext();
    }
    return sum;
}
bool deleteL1Element(LinkedList<int> &L1, LinkedList<int> L2)
{
    int sumL2 = sumLL(L2);
    Node<int> *pWalker1 = L1.getHead();
    while (pWalker1 != NULL)
    {
        if (pWalker1->getData() > sumL2)
        {
            L1.remove(pWalker1->getData());
            return true;
        }
        pWalker1 = pWalker1->getpNext();
    }
    return false;
}

int maxLL(LinkedList<int> L1)
{
    Node<int> *pWalker = L1.getHead();
    int max = pWalker->getData();
    while (pWalker != NULL)
    {
        if (max < pWalker->getData())
            max = pWalker->getData();
        pWalker = pWalker->getpNext();
    }
    return max;
}
void deleteL1ElementMax(LinkedList<int> &L1, LinkedList<int> L2)
{
    int maxL2 = maxLL(L2);
    while (L1.search(maxL2) != NULL)
    {
        L1.remove(maxL2);
    }
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
    L3 = createLLUsingConnect(L1, L2);
    cout << "Noi L1 vao L2\n";
    L3.display();

    // Cau b
    L3 = createLLUsingSub(L1, L2);
    cout << "Cac phan tu chi co trong L1 ma ko co trong L2\n";
    L3.display();

    // Cau c
    L3 = createLLUsingGiao(L1, L2);
    cout << "Cac phan tu vua co trong L1 vua co trong L2\n";
    L3.display();

    // Cau d
    L3 = createLLUsingHop(L1, L2);
    cout << "Cac phan tu hoac co trong L1 hoac co trong L2\n";
    L3.display();

    // Cau e
    L3 = createSumLL(L1, L2);
    cout << "Danh sach tong L3:\n";
    L3.display();

    // Cau f
    if (checkDistinctValue(L1, L2))
        cout << "L1 khong trung gia tri voi L2\n";
    else
        cout << "L1 trung gia tri voi L2\n";

    // Cau g
    if (deleteL1Element(L1, L2))
    {
        cout << "Cap nhat cac phan tu L1:\n";
        L1.display();
    }
    else
    {
        cout << "Khong xoa duoc phan tu nao!\n";
    }

    // Cau h
    deleteL1ElementMax(L1, L2);
    cout << "Cac phan tu trong L1 sau khi xoa gia tri lon nhat trong L2:\n";
    L1.display();
    return 0;
}