// union of two sorted array
#include <iostream>
#include <algorithm>
using namespace std;

void Union(int a[], int b[], int n, int m) // naive
{
    int c[n + m];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0; i < m; i++)
    {
        c[n + i] = b[i];
    }
    sort(c, c + n + m);
    int i = 0;
    while (i < n + m)
    {
        if (c[i] == c[i + 1])
            i++;
        else
        {
            cout << c[i] << " ";
            i++;
        }
    }
}
//=============================================================================

void printUnion(int a[], int b[], int m, int n)//effiecient
{

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j - 1] == b[j])
        {
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < m)
    {
        if (i == 0 || a[i] != a[i - 1])
            cout << a[i] << " ";
        i++;
    }
    while (j < n)
    {
        if (j == 0 || b[j] != b[j - 1])
            cout << b[j] << " ";
        j++;
    }
}

int main()
{
    int a[] = {2, 10, 20, 20};
    int n = sizeof(a) / sizeof(a[2]);
    int b[] = {3, 20, 40};
    int m = sizeof(b) / sizeof(b[2]);
    Union(a, b, n, m);
    cout << endl;
    printUnion(a, b, n, m);
    return 0;
}