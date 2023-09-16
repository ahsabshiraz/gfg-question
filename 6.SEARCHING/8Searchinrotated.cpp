// Search in sorted and Rotated array
#include <iostream>
using namespace std;

int Search(int arr[], int n, int key) // naive
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int RotatedarraySearch(int arr[], int x, int n) // efficient
{
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > arr[low]) // checking if left side is sorted
        {
            if (x >= arr[low] && arr[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }

        else // checking if right side is  sorted
        {
            if (arr[mid] < x && arr[high] >= x)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 40, 60, 5, 8};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << RotatedarraySearch(arr, 5, n);
    return 0;
}