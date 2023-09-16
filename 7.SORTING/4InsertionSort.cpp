// Insertion Sort
#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int a[] = {2, 4, 12, 84, 3, 352};
    int n = sizeof(a) / sizeof(a[2]);
    InsertionSort(a, n);
    for (auto x : a)
        cout << x << " ";
    return 0;
}