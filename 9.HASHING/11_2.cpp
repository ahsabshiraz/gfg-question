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
            res = i + 1;
        }
        // we only insert the element that we find for the first time to find the longest subarray
        if (h.find(presum) == h.end())
        {
            h.insert({presum, i});
        }
        if (h.find(presum - sum) != h.end())
        {
            res = max(res, i - h[presum - sum]);
            // cout << h[presum - sum] << " " << i << endl;
        }
    }
    return res;
}

int main()
{
    int a[] = {8, 3, -6, 6, 2, 1, 2};

    int n = sizeof(a) / sizeof(int);

    cout << maxlen(a, n, 3) << " ";

    return 0;
}