// Given an unsorted array and a number x, we need to find if there is a pair in the array with sum equal to x
#include <iostream>
using namespace std;
bool isPair(int arr[], int n, int x) // naive
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                return true;
            }
        }
    }
    return false;
}
// Given a sorted array and a sum ,find if there is a pair with given sum-----------------------------------------------------------------------
bool ispair(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == x)
            return true;
        else if ((arr[low] + arr[high]) > x)
            high--;
        else
            low++;
    }
    return false;
}
// Given a sorted array and a sum ,find if there is a triplet with given sum-----------------------------------------------------------------------

bool istriplet(int arr[], int n, int x)//naive
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] ==x)
                return true;
            }
        }
    }
    return false;
}
//--------------------------------efficient-------------------------------------------------------------------
bool ispair(int arr[], int l, int h, int x) // modifed ispair for this question
{
    int low = l, high = h;
    while (low < high)
    {
        if (arr[low] + arr[high] == x)
            return true;
        else if ((arr[low] + arr[high]) > x)
            high--;
        else
            low++;
    }
    return false;
}
bool IStriplet(int arr[], int n, int x) // efficient solution
{
    for (int i = 0; i < n; i++)
    {
        if (ispair(arr, i + 1, n - 1, x - arr[i]))
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {2, 4, 8, 9, 11, 12, 20, 30};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << isPair(arr, n, 13) << " ";
    cout << ispair(arr, n, 13) << " ";
    cout<<istriplet(arr,n,52)<<" ";
    cout << IStriplet(arr, n, 52);
    return 0;
}