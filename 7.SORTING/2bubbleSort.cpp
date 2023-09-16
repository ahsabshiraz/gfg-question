// BUbble sort
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void bubblesort(int arr[], int n) // optimised When the array was already sorted
{
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}
int main()
{
    int a[] = {2, 4, 12, 84, 3, 352};
    int n = sizeof(a) / sizeof(a[2]);
    BubbleSort(a, n);
    for (auto x : a)
        cout << x << " ";

    return 0;
}