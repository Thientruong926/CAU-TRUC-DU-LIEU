#include <iostream>
using namespace std;
class Array
{
    int *a;
    int size;

public:
    Array();
    ~Array();
    void push_back(int x);
    void binarySearch(int x);
};
Array::Array()
{
    size = 0;
    a = NULL;
}
Array::~Array()
{
    delete[] a;
}
void Array::push_back(int x)
{
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = a[i];
    temp[size] = x;
    delete[] a;
    size++;
    a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = temp[i];
    delete[] temp;
}
void Array::binarySearch(int x)
{
    Array idxl, idxr;
    int l = 0, r = size - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (x == a[m])
        {
            break;
        }
        else if (x < a[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
        idxl.push_back(l);
        idxr.push_back(r);
    }
    cout << "So lan chia doi mang la: " << idxl.size << endl;
    for (int i = 0; i < idxl.size; i++)
    {
        cout << "x = " << x << " nam trong doan [" << idxl.a[i] << ".." << idxr.a[i] << "]\n";
    }
}
int main()
{
    Array M;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        M.push_back(x);
    }
    int x;
    cin >> x;
    M.binarySearch(x);
    return 0;
}