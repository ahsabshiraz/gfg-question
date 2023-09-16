#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
// Q>given n ranges we have to find the maximum apprearing elements
int maxOcc(int L[], int R[], int n)
{

    int arr[1000]; // setting all value to zero
    arr[1000] = {0};
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        arr[L[i]]++;
        arr[R[i] + 1]--;
    }
    int max = arr[0];
    int res = 0;
    for (int i = 1; i < 1000; i++)
    {
        arr[i] += arr[i - 1];
        if (max < arr[i])
        {
            max = arr[i];
            res = i;
        }
    }
    return res;
}

int main()
{

    int L[] = {1, 2, 3}, R[] = {3, 5, 7}, n = 3;

    cout << maxOcc(L, R, n);
}