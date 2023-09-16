// Find largest element in the array

#include <iostream>
using namespace std;

int naiveLargest(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max; // returning the element
}

int effincientfind(int arr[], int n)
{
    int ind = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[ind])
        {
            ind = i;
        }
    }

    return ind; // returning the index
}

int main()
{
    int arr[10] = {33232, 6666666, 14, 1125, 16, 17};

    int max = naiveLargest(arr, 6);
    cout << max << " ";
    int max2 = effincientfind(arr, 6);
    cout << max2;
}
