#include <iostream>
using namespace std;

int partition(int arr[], int lb, int ub)
{
    int start = lb, end = ub, pivot = arr[lb];
    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]);
    return end;
}
int kthSmallest(int arr[], int n, int k)
{
    if (n < k)
        return -1;
    int l = 0, h = n-1;
    while (l <= h)
    {
        int p = partition(arr, l, h);
        if (p == k - 1)
            return p;
        else if (p > k - 1)
            h = p - 1;
        else
            l = p + 1;
    }
    return -1;
}
int main()
{

    int arr[] = {10, 4, 5, 8, 11, 6, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    int index = kthSmallest(arr, n, k);
    cout << arr[index];
}