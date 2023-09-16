#include <iostream>
#include <unordered_set>
using namespace std;
bool is0subarray(int a[], int n)
{
    int pre_sum = 0;
    unordered_set<int> h;
    for (int i = 0; i < n; i++)
    {
        pre_sum += a[i];
        if (h.find(pre_sum) != h.end())
        {
            return true;
        }
        if (pre_sum == 0)
        {
            return true;
        }

        else
        {
            h.insert(pre_sum);
        }
    }

    return false;
}
int main()
{
    int a[] = {-3, 4, -3, -1, 1};

    int n = sizeof(a) / sizeof(int);

    cout << is0subarray(a, n);
    return 0;
}