#include "LinkedList.h"

LinkedList<int> findSubArray(LinkedList<int> L1, LinkedList<int> L2)
{
    LinkedList<int> res;
    while (L2.search(L1.getHead()->getData()) == NULL)
    {
        L1.removeHead();
    }
    if (L1.getHead() == NULL)
        return res;
    while (L1.getHead()->getData() != L2.getHead()->getData())
        L2.removeHead();
    while (L1.getHead() != NULL && L2.getHead() != NULL && L1.getHead()->getData() == L2.getHead()->getData())
    {
        res.addTail(L1.getHead()->getData());
        L1.removeHead();
        L2.removeHead();
    }
    return res;
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

    L3 = findSubArray(L1, L2);
    if (L3.getHead() == NULL)
    {
        cout << "Khong ton tai day con giua L1 va L2" << endl;
    }
    else
    {
        cout << "Day con dau tien cua danh sach L1 ma con nay co trong danh sach L2:\n";
        L3.display();
    }
    return 0;
}