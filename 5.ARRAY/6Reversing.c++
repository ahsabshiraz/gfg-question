// Reverse array
#include <iostream>
using namespace std;

void reverse(int arr[], int n) // swapping
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, n);
    for (int n : arr)
        cout << n << " ";
}