// LONGEST SUBARRAY WITH EQUAL O's and 1's>>
// NAIVE SOLUTION

#include <iostream>
#include <unordered_set>
using namespace std;
int longestsub(int a[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int c0 = 0, c1 = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j] == 0)
            {
                c0++;
            }
            else
            {
                c1++;
            }
            if (c0 == c1)
                res = max(res, c0 + c1);
        }
    }
    return res;
}
int main()
{
    int a[] = {1,1,1,0,1,0};

    int n = sizeof(a) / sizeof(int);

    cout << longestsub(a, n);
    return 0;
}