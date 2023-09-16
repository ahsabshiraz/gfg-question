// SUB ARRAY WITH GIVEN SUM
// EFFICIENT SOLUTION
#include <iostream>
#include <unordered_set>
using namespace std;
int issum(int a[], int n, int sum)
{
    unordered_set<int> h;
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        presum += a[i];
        if (presum == sum)//if sub which is eqaul to sum is from ind-0 to avoid this add '0' in set explicitly
            return true;
        if (h.find(presum - sum) != h.end())
        {
            return true;
        }
        else
        {
            h.insert(presum);
        }
    }
    return false;
}
int main()
{
    int a[] = {5, 8, 6, 13};

    int n = sizeof(a) / sizeof(int);

    cout << issum(a, n, 14);
    return 0;
}
