//  Merge two sorted array
#include <iostream>
#include <algorithm>
using namespace std;
void Merge(int a[], int b[], int n, int m)
{
    int c[n + m];
    for (int i = 0; i < n; i++)
        c[i] = a[i];
    for (int j = 0; j < m; j++)
        c[n + j] = b[j];
    sort(c, c + n + m);
    for (auto x : c)
        cout << x << " ";
    cout << endl;
}

void merge(int a[], int b[], int n, int m)
{
    int c[m + n];
    int i = 0, j = 0;
    int x = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[x] = a[i];
            i++;
            x++;
        }
        else
        {
            c[x] = b[j];
            j++;
            x++;
        }
    }
    while (i < n)
    {
        c[x] = a[i];
        x++;
        i++;
    }
    while (j < m)
    {
        c[x] = b[j];
        x++;
        j++;
    }
    for (auto x : c)
        cout << x << " ";
}
int main()
{
    int a[] = {2, 4, 5, 13, 15, 20};
    int n = sizeof(a) / sizeof(a[2]);
    int b[] = {1, 3, 6, 14, 25};
    int m = sizeof(b) / sizeof(b[2]);
    Merge(a, b, n, m);

    merge(a, b, n, m);

    return 0;
}