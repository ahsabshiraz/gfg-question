// Count 1s in a sorted array
#include <iostream>
using namespace std;
int Count1s(int arr[], int n, int key)
{
    int mid, low = 0, high = n - 1;
    while (low <= high)
    {
        mid = low + high / 2;
        if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return n - mid;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {0, 0, 0, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << Count1s(arr, n, 1);
    return 0;
}