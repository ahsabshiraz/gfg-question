// SUB ARRAY WITH 0 SUM.
// NAIVE SOLUTION
#include <iostream>
using namespace std;
bool is0subarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += a[j];
            if (curr_sum == 0)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int a[] = {-1,4,-3,5,1};

    int n = sizeof(a) / sizeof(int);

    cout << is0subarray(a, n);
    return 0;
}