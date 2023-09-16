// MAXimum sum subarray
#include <iostream>
using namespace std;

int maxSum(int arr[], int n) // naive
{
    int res = 0, sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            res = max(res, sum);
        }
    }
    return res;
}

int Maxsum(int arr[], int n)// EFFICIeNT SOLuTIon  
{
    int maxending = arr[0], res = arr[0];  
    for (int i = 1; i < n; i++)
    {
        maxending = max(maxending + arr[i], arr[i]); // we are comparinig which sub array is maximum current subarray or maxending(which maximum of last subarray) 
        res = max(maxending, res);
    }
    return res;
}

int main()
{
    int arr[] = {1, 1, -2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    cout << Maxsum(arr, n);
    return 0;
}