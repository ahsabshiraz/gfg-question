//  Search in infinte size array
#include <iostream>
using namespace std;
int search(int arr[], int n) // naive
{
    int i = 0;
    while (true)
    {
        if (arr[i] == n)
            return i;
        if (arr[i] > n)
            return -1;
        i++;
    }
}
//---------------------------------------------------efficient
int binarysearch(int arr[], int l, int h, int key)
{
    int mid, low = l, high = h;
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

int InfinitarraySearch(int arr[], int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (arr[i] < x)
        i = i * 2;
    if (arr[i] == x)
        return i;

    return binarysearch(arr, i / 2 + 1, i - 1, x);
}
int main()
{
    int arr[] = {1, 10, 25, 30, 35, 60, 65, 75, 78, 100, 200, 320, 1000};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << search(arr, 320) << " ";
    cout << InfinitarraySearch(arr, 320);
    return 0;
}