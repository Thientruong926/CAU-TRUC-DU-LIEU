#include <iostream>
using namespace std;
class Array
{
    int *a;
    int size;

public:
    Array();
    ~Array();
    void linearSearch(int key);
    void push_back(int x);
};
Array::Array()
{
    size = 0;
    a = NULL;
}
Array::~Array()
{
    delete a;
}
void Array::linearSearch(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == key)
        {
            cout << i << ' ';
        }
    }
}
void Array::push_back(int x)
{
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = a[i];
    }
    temp[size] = x;
    size++;
    delete[] a;
    a = new int[size];
    for (int i = 0; i < size; i++)
    {
        a[i] = temp[i];
    }
    delete[] temp;
}
int main()
{
    int n;
    cin >> n;
    Array array;
    while (n--)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }
    int x;
    cin >> x;
    array.linearSearch(x);
    return 0;
}