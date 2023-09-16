// Index of First Occurance
#include <iostream>
using namespace std;

int lastINDEX(int arr[], int low, int high, int key, int n) // recursive
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] > key)
        return lastINDEX(arr, low, mid - 1, key, n);
    else if (arr[mid] < key)
        return lastINDEX(arr, mid + 1, high, key, n);
    else
    {
        if (mid == n - 1 || arr[mid] != arr[mid + 1])
            return mid;
        else

            return lastINDEX(arr, mid + 1, high, key, n);
    }
}

int lastIndex(int arr[], int n, int key)//iterative
{
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
        mid = (low + high )/ 2;
        if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
        else
        {
            if (mid == n - 1 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 7,7};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << lastINDEX(arr, 0, n, 7, n)<<" ";
    cout<<lastIndex(arr,n,7);
    return 0;
}