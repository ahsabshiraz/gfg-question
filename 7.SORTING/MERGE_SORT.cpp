#include <iostream>
using namespace std;

void Merge(int arr[], int l, int h, int mid)
{
    int i = l, j = mid + 1, k = l, B[100];
    while (i <= mid and j <= h)
    {
        if (arr[i] < arr[j])
            B[k++] = arr[i++];
        else
            B[k++] = arr[j++];
    }
    for (; i <= mid; i++)
        B[k++] = arr[i];
    for (; j <= h; j++)
        B[k++] = arr[j];
    for (int i = l; i <= h; i++)
        arr[i] = B[i];
}

void mergeSORT(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSORT(arr, l, mid);
        mergeSORT(arr, mid + 1, h);
        Merge(arr, l, h, mid);
    }
}

int main()
{
    int a[] = {3, 13, 4, 5, 1, 51, 2, 7, 12, 54};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSORT(a, 0, n-1);
    for (int s : a)
        cout << s << " ";
    return 0;
}