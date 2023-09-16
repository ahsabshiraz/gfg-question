#include <iostream>
using namespace std;

int partition(int arr[], int lb, int ub)
{
    int start = lb, end = ub, pivot = arr[lb];
    while (start < end)
    {
        while (pivot >= arr[start])
            start++;
        while (pivot < arr[end])
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[lb], arr[end]); // lb is index of pivot that we chosse
    return end;
}

void QuickSORT(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int j = partition(arr, lb, ub);
        QuickSORT(arr, lb, j);
        QuickSORT(arr, j + 1, ub);
    }
}
int main()
{
    int a1[] = {3, 13, 4, 5, 1, 51, 2, 7, 12, 54};
    int n = sizeof(a1) / sizeof(a1[0]);
    QuickSORT(a1, 0, n - 1);
    for (int s1 : a1)
        cout <<"-"<< s1 << "-";
    return 0;
}