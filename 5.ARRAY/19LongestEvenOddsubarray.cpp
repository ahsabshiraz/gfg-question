// LONGEST SUB-array contaning even odd elements consecutively
#include <iostream>
using namespace std;
int maxEvenOdd(int arr[], int n) // naive
{
    int res = 1, count = 1;
    for (int i = 1; i < n; i++)
    {
        count = 1;
        for (int j = i; j < n; j++)
        {
            if (arr[j] % 2 == 0 && arr[j - 1] % 2 != 0 || arr[j - 1] % 2 == 0 && arr[j] % 2 != 0)
                count++;
            else
                break;
        }
        res = max(res, count);
    }
    return res;
}
int MaxEvenOdd(int arr[], int n) // effecient solution (BASED ON )(KAINDEN ALgorithm)
{
    int res = 1, count = 1;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] % 2 == 0 && arr[j - 1] % 2 != 0 || arr[j - 1] % 2 == 0 && arr[j] % 2 != 0)
        {
            count++;
            res = max(res, count);
        }
        else
            count = 1;
    }
    return res;
}

int main()
{
    int arr[] = {5, 10, 20, 6, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxEvenOdd(arr, n) << endl;
    cout << MaxEvenOdd(arr, n) << endl;
    return 0;
}