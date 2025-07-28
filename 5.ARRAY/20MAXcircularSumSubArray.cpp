// Maximum circular sum of sub array in the Given array
#include <iostream>
#include <vector>
#include <climits>
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
        arr[i] = -arr[i]; // invertion
    }
    int max_circular = arr_sum + normalMaxSum(arr, n);
    return max(max_circular, max_normal);
}

//! 3

//^ ______         ______
//? 3,4,6,|-8,4,-7|,10,-2 -> A=ans using kaidensAlog in straight array
//^ -----          ------
//& s1       s2      s1
//! s2=minimum sum
//! s1=totalSumArray-s2
//* ans=max(s1,A)

int ans(vector<int> a)
{
    int min = INT_MAX, max = INT_MIN;
    int s1 = 0, s2 = 0, s = 0;
    for (auto i : a)
    {
        s += i; // sum of all elements

        // maximum sum-subarray
        s1 += i;
        if (s1 > max)
            max = s1;
        if (s1 < 0)
            s1 = 0;

        // minimum sum-subarray
        s2 += i;
        if (s2 < min)
            min = s2;
        if (s2 > 0) // we find the largest negative subarray
            s2 = 0;
    }

    if (max < 0) // when whole array is negative
        return max;
    return max > s - min ? max : s - min;
}

int main()
{
    int arr[] = {5, -2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> a = {5, -2, 3, 4};
    cout << maxCircular(arr, n) << endl;
    cout << overallMaxSum(arr, n) << endl;
    cout << ans(a);
    return 0;
}