// Majority element in array which appears more n/2 times in the whole array.
#include <iostream>
using namespace std;

int findMajority(int arr[], int n) // naive
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
            if (count > n / 2)
                return i;
        }
    }
    return -1;
}

int FindMajority(int arr[], int n) // Effecient
{
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[res])
            count++;
        else
            count--;
        if (count == -1) // in gfg they use if(count==0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    cout << arr[res];
    for (int i = 0; i < n; i++)
        if (arr[res] == arr[i])
            count++;
    if (count <= n / 2)
        res = -1;

    return res;
}

int main()
{
    int arr[] = {6, 6, 7, 8, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMajority(arr, n) << endl; // returns index of the maximum element which is greater then n/2
    cout << FindMajority(arr, n);
    return 0;
}