//part-2 repeating element 
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

int repeat(int arr[], int n)
{
    int slow = arr[0], fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while (slow != fast);

    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
int repeat2(int arr[], int n)//modified version it handels array having elements from 0
{
    int slow = arr[0]+1, fast = arr[0]+1;

    do
    {
        slow = arr[slow]+1;
        fast = arr[arr[fast+1]]+1;

    } while (slow != fast);

    slow = arr[0]+1;

    while (slow != fast)
    {
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }
    return slow-1;
}

int main()
{

    int arr[] = {1, 3, 2, 4, 6, 5, 7, 3}, n = 8;

    cout << repeat(arr, n);

    return 0;
}