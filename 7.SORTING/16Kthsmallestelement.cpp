#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int KthSmallElement(int arr[], int n, int k) // naive
{
    sort(arr, arr + n);
    return arr[k - 1];
}

//===========================================================================================
//Quick select algorithm 
int partition(int arr[], int lb, int ub)
{
    int start = lb, end = ub, pivot = arr[lb];
    while (start < end)
    {
        while (pivot >= arr[start])
            start++;
        while (pivot < arr[end])
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]); // lb is index of pivot that we chosse
    return end;
}

int kthSmallest(int arr[], int n, int k) // works better in average
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = partition(arr, l, r);
        if (p == k - 1)
            return p;
        else if (p > k - 1)
            r = p - 1;
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