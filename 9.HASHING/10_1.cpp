// SUB ARRAY WITH GIVEN SUM
// NAIVE SOLUTION
#include <iostream>
using namespace std;
bool issubarrsum(int a[], int n,int sum)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += a[j];
            if (curr_sum == sum)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int a[] = {5,8,6,13};

    int n = sizeof(a) / sizeof(int);

    cout << issubarrsum(a, n,14);
    return 0;
}