#include "LinkedList.h"

// Kiem tra so nguyen to
bool checkPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
LinkedList<int> primeList(LinkedList<int> ll)
{
    LinkedList<int> res;
    Node<int> *pWalker = ll.getHead();
    while (pWalker != NULL)
    {
        if (checkPrime(pWalker->getData()) && res.search(pWalker->getData()) == NULL)
            res.addTail(pWalker->getData());
        pWalker = pWalker->getpNext();
    }
    return res;
}

int calculateAverage(LinkedList<int> ll)
{
    Node<int> *pWalker = ll.getHead();
    int sum = 0, cnt = 0;
    if (pWalker == NULL)
        return 0;
    while (pWalker != NULL)
    {
        cnt++;
        sum += pWalker->getData();
        pWalker = pWalker->getpNext();
    }
    return sum / cnt;
}

int countList(LinkedList<int> ll, int n)
{
    Node<int> *pWalker = ll.getHead();
    int cnt = 0;
    while (pWalker != NULL)
    {
        if (n == pWalker->getData())
            cnt++;
        pWalker = pWalker->getpNext();
    }
    return cnt;
}

// Kiem tra so chinh phuong
bool ktcp(int x)
{
    if (x < 0)
        return false;
    int n = sqrt(x);
    if (n * n == x)
        return true;
    return false;
}
int cp(LinkedList<int> ll)
{
    int res = -1;
    Node<int> *pWalker = ll.getHead();
    while (pWalker != NULL)
    {
        if (ktcp(pWalker->getData()))
            res = pWalker->getData();
        pWalker = pWalker->getpNext();
    }
    return res;
}

void findkIndex(LinkedList<int> ll, int k)
{
    if (k < 1 || k > ll.getSize())
    {
        cout << "So nguyen k khong hop le" << endl;
    }
    else
    {
        Node<int> *pWalker = ll.getHead();
        while (--k)
        {
            pWalker = pWalker->getpNext();
        }
        cout << "Phan tu thu k trong danh sach la: " << pWalker->getData() << endl;
    }
}

int findMinElement(LinkedList<int> ll)
{
    Node<int> *pWalker = ll.getHead();
    int min = pWalker->getData();
    while (pWalker->getpNext() != NULL)
    {
        pWalker = pWalker->getpNext();
        int tmp = pWalker->getData();
        if (min > tmp)
            min = tmp;
    }
    return min;
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

void insertAscendingList(LinkedList<int> &ll, const int data)
{
    Node<int> *pWalker = ll.getHead(), *temp = NULL;
    while ((pWalker != NULL) && (pWalker->getData() <= data))
    {
        temp = pWalker;
        pWalker = pWalker->getpNext();
    }
    if (temp == NULL)
        ll.addHead(data);
    else if (pWalker == NULL)
        ll.addTail(data);
    else
        ll.addAfter(temp, data);
}

bool checkPerfectNumber(int x)
{
    int sum = 0;
    for (int i = 1; i <= x / 2; i++)
    {
        if (x % i == 0)
            sum += i;
    }
    if (sum == x)
        return true;
    return false;
}
void changePNToZero(LinkedList<int> &ll)
{
    Node<int> *pWalker = ll.getHead();
    while (pWalker != NULL)
    {
        if (checkPerfectNumber(pWalker->getData()))
            pWalker->setData(0);
        pWalker = pWalker->getpNext();
    }
}

int main()
{
    LinkedList<int> ll;

    // Cau a: Nhap danh sach lien ket don cac so nguyen bang cach them tung phan tu vao cuoi danh sach
    cout << "Nhap danh sach lien ket don: ";
    int x;
    while (cin >> x)
    {
        ll.addTail(x);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Cau b: Xuat danh sach ra man hinh
    cout << "Hien thi danh sach lien ket don:\n";
    ll.display();

    // Cau c: Liet ke cac so nguyen to co trong danh sach
    LinkedList<int> res = primeList(ll);
    cout << "Cac so nguyen to co trong danh sach:\n";
    res.display();

    // Cau d: Tinh trung binh cong cua cac phan tu trong danh sach
    cout << "Trung binh cong cua cac phan tu trong danh sach: " << calculateAverage(ll) << endl;

    // Cau e:
    cout << "Dem so lan xuat hien cua mot so nguyen nhap tu ban phim co trong danh sach" << endl;
    cout << "Nhap so nguyen: ";
    int n;
    cin >> n;
    cout << "So lan xuat hien cua " << n << " trong danh sach la: " << countList(ll, n) << endl;

    // Cau f: Tim so chinh phuong cuoi cung trong danh sach
    int scp = cp(ll);
    if (scp == -1)
        cout << "Khong co so chinh phuong trong danh sach\n";
    else
        cout << "So chinh phuong cuoi cung trong danh sach la: " << scp << endl;

    // Cau g:
    int k;
    cout << "Tim va tra ve phan tu thu k trong danh sach tinh tu dau danh sach" << endl;
    cout << "Nhap so k: ";
    cin >> k;
    findkIndex(ll, k);

    // Cau h: Tim phan tu co gia tri nho nhat trong danh sach
    int min = findMinElement(ll);
    cout << "Phan tu co gia tri nho nhat trong danh sach: " << min << endl;

    // Cau i:
    cout << "Them mot phan tu vao sau phan tu q trong danh sach" << endl;
    int qValue, insertValue;
    cout << "Nhap gia tri cua phan tu q: ";
    cin >> qValue;
    cout << "Nhap gia tri cua phan tu can them: ";
    cin >> insertValue;
    Node<int> *q = ll.search(qValue);
    ll.addAfter(q, insertValue);
    cout << "Cap nhat danh sach: " << endl;
    ll.display();

    // Cau j:
    cout << "Them mot phan tu vao danh sach sao cho phan tu them vao khong trung voi cac phan tu da co trong danh sach\n";
    int insertUniqueValue;
    cout << "Nhap phan tu can them: ";
    cin >> insertUniqueValue;
    Node<int> *insertUniqueNode = ll.search(insertUniqueValue);
    if (insertUniqueNode == NULL)
    {
        ll.addTail(insertUniqueValue);
        cout << "Cap nhat danh sach: " << endl;
        ll.display();
    }
    else
    {
        cout << "Phan tu " << insertUniqueValue << " da co trong danh sach" << endl;
    }

    // Cau k
    int k2;
    cout << "Xoa k phan tu o dau danh sach" << endl;
    cout << "Nhap so k: ";
    cin >> k2;
    if (k2 > ll.getSize())
    {
        cout << "So k khong hop le" << endl;
    }
    else
    {
        while (k2--)
        {
            ll.removeHead();
        }
        cout << "Cap nhat danh sach: " << endl;
        ll.display();
    }

    // Cau l
    cout << "Xoa phan tu co gia tri bang x trong danh sach\n";
    int x2;
    cout << "Nhap gia tri x: ";
    cin >> x2;
    while (true)
    {
        if (ll.search(x2) != NULL)
        {
            ll.remove(x2);
        }
        else
            break;
    }
    cout << "Cap nhat danh sach:" << endl;
    ll.display();

    // Cau m
    cout << "Xoa mot phan tu sau phan tu q trong danh sach\n";
    int qValue2;
    cout << "Nhap phan tu q: ";
    cin >> qValue2;
    Node<int> *q2 = ll.search(qValue2);
    ll.removeAfter(q2);
    cout << "Cap nhat danh sach: " << endl;
    ll.display();

    // Cau n
    deleteDuplicateElement(ll);
    cout << "Danh sach sau khi xoa cac phan tu lap lai: " << endl;
    ll.display();

    // Cau o
    interchangeSortLL(ll);
    cout << "Danh sach sau khi duoc sap xep: " << endl;
    ll.display();

    // Cau p
    cout << "Them mot phan tu vao danh sach tang dan" << endl;
    int insertValue2;
    cout << "Nhap gia tri cua phan tu can them: ";
    cin >> insertValue2;
    insertAscendingList(ll, insertValue2);
    ll.display();

    // Cau q
    changePNToZero(ll);
    cout << "Cap nhat danh sach: " << endl;
    ll.display();

    return 0;
}