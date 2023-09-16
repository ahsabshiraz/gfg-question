// Index of first occurance
#include <iostream>
using namespace std;

int firstOccurance(int arr[], int n, int key) // naive
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int RfirstOccurance(int arr[], int low, int high, int key) // efficient recursive
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] < key)
        return RfirstOccurance(arr, mid + 1, high, key);
    else if (arr[mid] > key)
        return RfirstOccurance(arr, low, mid - 1, key);
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
            return mid;
        else
            return RfirstOccurance(arr, low, mid - 1, key);
    }
}
int IfirstOccurance(int arr[], int n, int key) // efficient iterative
{
    int low = 0, high = n - 1;
    int mid;
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
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 5, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << firstOccurance(arr, n, 5) << endl;
    cout << RfirstOccurance(arr, 0, n - 1, 5) << endl;
    cout << IfirstOccurance(arr, n, 5);
    return 0;
}