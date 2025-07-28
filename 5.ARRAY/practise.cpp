#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isEqPoint1(int arr[], int n) // prefixSum technique used here
{
    int sum = 0;
    int lsum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    for (int i = 0; i < n; i++)
    {
        if (lsum == sum - arr[i])
            return true;
        else
        {
            lsum += arr[i];
            sum -= arr[i];
        }
    }
    return false;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6};
    int n = sizeof(arr) / sizeof(arr[1]);
   
    // prefixSum(arr, n);
    // cout << getSum1(arr, l, r);
    // cout << isEqpoint(arr, n) << endl;
    cout << isEqPoint1(arr, n);
    return 0;
}