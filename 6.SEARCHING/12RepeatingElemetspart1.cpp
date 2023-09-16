// Repeating element (part-1)

#include <iostream>
#include <algorithm>
using namespace std;

int Repeat(int arr[], int n) // super naive
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                return arr[i];
        }
    return -1;
}
int Repeat2(int arr[], int n) // naive
{
    sort(arr, arr + n - 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
            return arr[i];
    }
    return -1;
}
int Repeat3(int arr[], int n) // efficient
{
    bool visited[100] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[arr[i]]) // visited already then return true
            return arr[i];
        visited[arr[i]] = true;
    }
    return -1;
}
int main()
{
    int arr[] = {0,2,1,3,2,2};
    int n = sizeof(arr) / sizeof(arr[1]);
    cout << Repeat(arr, n) << " ";
    cout << Repeat2(arr, n) << " ";
    cout << Repeat3(arr, n);

    return 0;
}