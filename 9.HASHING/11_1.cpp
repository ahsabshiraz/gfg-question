// LONGEST SUB-ARRAY WITH GIVEN SUM
// NAIVE SOLUTION
#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int maxlen(int a[], int n, int sum)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += a[j];
            if (curr_sum == sum)
            {
                res = max(res, j - i + 1);
            }
        }
    }

    return res;
}

int main()
{
    int a[] = {5, 2, 3, 4};

    int n = sizeof(a) / sizeof(int);

    cout << maxlen(a, n, 5);
    return 0;
}