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
    int linearSearch(int x);
    void pop(int x);
    void display();
};
Array::Array()
{
    size = 0;
    a = new int[size];
}
Array::~Array()
{
    delete a;
    size = 0;
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
int Array::linearSearch(int x)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}
void Array::pop(int x)
{
    while (linearSearch(x) != -1)
    {
        int idx = linearSearch(x);
        int *temp = new int[size - 1];
        for (int i = 0; i < idx; i++)
        {
            temp[i] = a[i];
        }
        for (int i = idx + 1; i < size; i++)
        {
            temp[i - 1] = a[i];
        }
        delete[] a;
        size--;
        a = new int[size];
        for (int i = 0; i < size; i++)
        {
            a[i] = temp[i];
        }
        delete[] temp;
    }
}
void Array::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    Array array;
    while (n--)
    {
        int e;
        cin >> e;
        array.push_back(e);
    }
    int x;
    cin >> x;
    array.pop(x);
    array.display();
}