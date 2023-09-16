// Merge Function For Merge Sort
#include <iostream>
using namespace std;
void merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = a[mid + j + 1];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            k++;
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (r > l) // atleast two element
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int b[] = {10, 15, 20, 40, 8, 11, 125, 22, 25};
    int m = sizeof(b) / sizeof(b[2]);
    int mid = 3;
    mergeSort(b, 0, 8);
    for (auto x : b)
        cout << x << " ";
    return 0;
}