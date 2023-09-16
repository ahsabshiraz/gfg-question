// Check if the array is sorted
#include <iostream>
using namespace std;

bool sorted(int arr[], int n) // naive method
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                return false;
        }
    return true;
}

bool SORTED(int arr[],int n) // EFFICIENT method
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return false;

    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sorted(arr, n)<<endl;
     cout << SORTED(arr, n);
    return 0;
}