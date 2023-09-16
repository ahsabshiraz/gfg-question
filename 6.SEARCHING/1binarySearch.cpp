// Binary Search (ITerative) and (Recursive)
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) // iterative
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)

            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Rbinarysearch(int arr[], int low, int high, int key)//recursive binary search
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return Rbinarysearch(arr, low, mid - 1, key);
    else
        return Rbinarysearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 77,3};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << binarySearch(arr, n, 77) << endl;
    cout << Rbinarysearch(arr, 0, n, 3);
    return 0;
}
