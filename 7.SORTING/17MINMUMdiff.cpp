#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minDiff(int a[], int n) // naive
{
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            res = min(res, abs(a[i] - a[j]));
        }
    }
    return res;
}
int mindiff(int a[], int n)//efficient
{
    int res = INT_MAX;
    sort(a, a + n);
    for (int i = 1; i < n; i++)
    {
        res = min(a[i] - a[i - 1], res);
    }
    return res;
}
int main()
{

    int arr[] = {1, 8, 12, 5, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minDiff(arr, n) << " ";
    cout << mindiff(arr, n);
    return 0;
}