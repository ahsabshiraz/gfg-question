// Maximum circular sum of sub array in the Given array
#include <iostream>
using namespace std;

int maxCircular(int arr[], int n) // naive
{
    int curr_max = 0;
    int curr_sum = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        curr_max = arr[i];
        curr_sum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            curr_sum += arr[index];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    }
    return res;
}
//------------------------------------------------------------------------------------effecient

int normalMaxSum(int arr[], int n)
{
    int maxending = arr[0], res = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxending = max(maxending + arr[i], arr[i]);
        res = max(res, maxending);
    }
    return res;
}
int overallMaxSum(int arr[], int n)
{
    int max_normal = normalMaxSum(arr, n);
    if (max_normal < 0)
        return max_normal;
    int arr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];//invertion
    } 
    int max_circular = arr_sum + normalMaxSum(arr, n);
    return max(max_circular, max_normal);
}

int main()
{
    int arr[] = {5, -2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxCircular(arr, n)<<endl;
    cout << overallMaxSum(arr, n);
    return 0;
}