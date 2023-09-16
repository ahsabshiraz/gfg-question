// Traping Rain Water.
#include <iostream>
#include <cmath>
using namespace std;

int getwater(int arr[], int n) // naive
{
    int lmax, rmax, res = 0;
    lmax = rmax = 0;
    for (int i = 0; i < n; i++)
    {
        lmax = arr[i]; // find lmax and rmax for every index
        for (int j = i - 1; j >= 0; j--)
            lmax = max(lmax, arr[j]);

        rmax = arr[i];
        for (int j = i + 1; j < n; j++)
            rmax = max(rmax, arr[j]);

        res = res + (min(rmax, lmax) - arr[i]);
    }

    return res;
}

int getWater(int arr[], int n) // EFFICIENt SOLUtioN  // here we preprocess the lamx and rmax of every element int lmax[] for left and rmax for right
{
    int res = 0;
    int rmax[n], lmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(arr[i], lmax[i - 1]);
    }
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(rmax[i + 1], arr[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        res += min(lmax[i], rmax[i]) - arr[i];
    }
    return res;
}

int main()
{

    int arr[] = {3, 0, 1, 2, 5}, n = 5;
    cout << getwater(arr, n) << endl;
    cout << getWater(arr, n);
}