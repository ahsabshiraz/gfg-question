// LONGEST SUB-ARRAY WITH GIVEN SUM
// EFFICIENT  SOLUTION
#include <iostream>
#include <unordered_map>
using namespace std;

int maxlen(int a[], int n, int sum)
{
    unordered_map<int, int> h;
    int presum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        presum += a[i];
        if (presum == sum)
        {
            res == i + 1;
        }
        if (h.find(presum) == h.end())
        {
            h.insert({presum, i});
        }
        if (h.find(presum - sum) != h.end())
        {
            res = max(res, i - h[presum - sum]);
        }
    }
    return res;
}

int main()
{
    int a[] = {8, 3, 1, 5, -6, 6, 2, 2};

    int n = sizeof(a) / sizeof(int);

    cout << maxlen(a, n, 4);
    return 0;
}