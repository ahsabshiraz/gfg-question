// Find peak element (a[i-1]<a[i]>a[i+1])

#include <iostream>
using namespace std;
int peakElement(int arr[], int n) // naive
{
    if (n == 1)
        return arr[0];
    if (arr[0] >= arr[1])
        return arr[0];
    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
    return -1;
}

int Peakelement(int arr[], int n) // efficient
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        cout << low << " " << mid << " " << high << endl;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
            return mid;
        else if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 2, 15, 7, 8};
    int n = sizeof(arr) / sizeof(arr[1]);
    // cout << peakElement(arr, n) << " "; // returns element
    cout << Peakelement(arr, n); // returns index

    return 0;
}