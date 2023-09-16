#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Q> we have o find sum of elements for(given indexes ) in from of queries EX-getSum(1,4) //1 ans 4 are indexes to get sum from 1 index to 4

int getsum(int arr[], int n, int l, int r) // naive
{
    if (l < 0 || r > n - 1)
        return -1;
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += arr[i];
    }
    return sum;
}

//===========================
int prefix_sum[1000];
void prefixSum(int arr[], int n)
{

    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }
}
int getSum1(int arr[], int l, int r) // efficient
{
    if (l != 0)
        return prefix_sum[r] - prefix_sum[l - 1];
    else
        return prefix_sum[r];
}

// Q> find the equilibrium point(index) in the given  array  which measn after removing that index all  the elements in it's right is get's equal to all  the elemnets in it's right

bool isEqpoint(int arr[], int n) // naive
{
    for (int i = 0; i < n; i++)
    {
        int lsum = 0;
        int rsum = 0;
        for (int j = 0; j < i; j++)
            lsum += arr[j];
        for (int j = i + 1; j < n; j++)
            rsum += arr[j];
        if (lsum == rsum)
            return true;
    }
    return false;
}
bool isEqPoint1(int arr[], int n) // prefixSum technique used here
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int l_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (l_sum == sum - arr[i])
            return true;
        cout << l_sum << " ";
        l_sum += arr[i];
        cout << sum << endl;
        sum -= arr[i];
    }
    return false;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6};
    int n = sizeof(arr) / sizeof(arr[1]);
    int l = 0, r = 1;
    // prefixSum(arr, n);
    // cout << getSum1(arr, l, r);
    // cout << isEqpoint(arr, n) << endl;
    cout << isEqPoint1(arr, n);
    return 0;
}