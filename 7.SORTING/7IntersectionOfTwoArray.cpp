// Intersection Of Two Sorted Array
#include <iostream>
using namespace std;
void Intersection(int a[], int b[], int n, int m) // naive
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j] && (i == 0 || a[i] != a[i - 1]))
            {
                cout << a[i] << " ";
                break;
            }
        }
    }
}

void INtersection(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (i > 0 && a[i] == a[i - 1]) // handel the duplicates
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int n = sizeof(a) / sizeof(a[2]);
    int b[] = {5, 10, 10, 15, 30};
    int m = sizeof(b) / sizeof(b[2]);
    // Intersection(a, b, n, m);
    INtersection(a, b, n, m);
    return 0;
}