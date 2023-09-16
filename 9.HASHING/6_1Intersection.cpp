// INTERSECTION OF UNSORTED ARRAY
// NAIVE SOLUTION
#include <iostream>
using namespace std;
int intersection(int a[], int b[], int m, int n)
{
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)// dealing with duplicates
        {
            if (a[i] == a[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;

        for (int t = 0; t < n; t++)
        {
            if (a[i] == b[t])
            {
                res++;
                break;
            }
        }
    }
    return res;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    int m = sizeof(a) / sizeof(int);
    int n = sizeof(b) / sizeof(int);
    cout << intersection(a, b, m, n);
    return 0;
}