// LONGEST COMMON SUNARRAY EITH GIVEN SUM
// NAIVE SOLUTION
#include <iostream>
#include <unordered_set>
using namespace std;
int mapcommon(int a[], int b[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j < n; j++)
        {
            sum1 += a[j];
            sum2 += b[j];
            if (sum1 == sum2)
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}
int main()
{
    int a[] = {0, 1, 0, 0, 0, 0};
    int b[] = {1, 0, 1, 0, 0, 1};
    int n = sizeof(a) / sizeof(int);

    cout << mapcommon(a,b, n);
    return 0;
}