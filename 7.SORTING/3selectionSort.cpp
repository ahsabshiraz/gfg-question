// Selection sort
#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)//i<n-1(bcz last element is sorted automatically)
    {
        int min_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_ind] > arr[j])
                min_ind = j;
        }
        swap(arr[i], arr[min_ind]);
    }
}

int main()
{
    int a[] = {2, 4, 12, 84, 3, 352};
    int n = sizeof(a) / sizeof(a[2]);
    SelectionSort(a, n);  
    for (auto x : a)          
        cout << x << " ";
    return 0;
}                                                                               