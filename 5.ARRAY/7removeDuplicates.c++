// Remove duplicates
#include<vector>
#include <iostream>
using namespace std;

int removeDUP(int arr[], int n) // Naive solution
{
    int temp[n];
    temp[0] = arr[0];
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (temp[res - 1] != arr[i])
        {
            temp[res] = arr[i];
            res++;
        }
    }
    for (int i = 0; i < res; i++)
    {
        arr[i] = temp[i];
    }

    return res;
}

int REMOVEdup(int arr[], int n) // Efficient solution
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res-1] != arr[i])
        {
            arr[res] = arr[i];
            // cout << res << " " << i << endl;
            res++;
        }
    }
    return res;
}
int removeDuplicates(vector<int> &nums)
{
    int ptr = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
            nums[ptr++] = nums[i];
    }
    return ptr;
}
int main()
{
    int arr[] = {11, 11, 1, 1, 2, 2, 2, 33, 33};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int res = removeDUP(arr, n);
    // for (int i = 0; i < res; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << endl;
    int res1 = REMOVEdup(arr, n);
    for (int i = 0; i < res1; i++)
    {
        cout << arr[i] << " ";
    }
}