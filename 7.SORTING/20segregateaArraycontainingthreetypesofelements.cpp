// segregate an array of elements containing three types of elements.
#include <bits/stdc++.h>
using namespace std;
// Sort an array of 0s, 1s, 2s.
void sort(int arr[], int n) // naive
{
    int temp[n], i = 0;

    for (int j = 0; j < n; j++)
        if (arr[j] == 0)
            temp[i++] = arr[j];
    for (int j = 0; j < n; j++)
        if (arr[j] == 1)
            temp[i++] = arr[j];
    for (int k = 0; k < n; k++)
        if (arr[k] == 2)
            temp[i++] = arr[k];
    for (int j = 0; j < n; j++)
        arr[j] = temp[j];
}

void Sort(int arr[], int n)
{                              // efficient(dutch national algorithm)
    int l = 0, h = n - 1, mid = 0;
    while (mid <= h)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[l], arr[mid]);
            l++;
            mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[h], arr[mid]);
            h--;
            break;
        }
    }
}
int main()
{

    int arr[] = {0, 1, 1, 2, 0, 1, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);

    for (int x : arr)
        cout << x << " ";
}