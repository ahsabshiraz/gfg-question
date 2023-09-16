// UNION OF UNSORTED ARRAY
// EFFICIENT SOLUTION

#include <iostream>
#include <unordered_set>
using namespace std;

void Union(int a[], int b[], int m, int n) // naive
{
    int temp[m + n];
    int j = 0;
    int ind = 0, x;
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j <= ind; j++) // copying all the element of a[] which is not already present in temp[]
        {
            if (a[i] == temp[j])
                break;
            else if (j == ind)
            {
                temp[ind] = a[i];
                ind++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= ind; j++) // copying all the element of b[] which is not already present in temp[]
        {
            if (b[i] == temp[j])
                break;
            else if (j == ind)
            {
                temp[ind] = b[i];
                ind++;
                break;
            }
        }
    }
    for (int i = 0; i < ind; i++)
        cout << temp[i] << " ";
}

int unioncount(int a[], int b[], int m, int n) // efficient
{
    unordered_set<int> h(a, a + m);
    for (int i = 0; i < n; i++)
    {
        h.insert(b[i]);
    }
    return h.size();
}

int main()
{
    int a[] = {10, 30, 10};
    int b[] = {5, 10, 5, 12};
    int m = sizeof(a) / sizeof(int);
    int n = sizeof(b) / sizeof(int);
    Union(a, b, m, n);
    // cout << unioncount(a, b, m, n);
    return 0;
}