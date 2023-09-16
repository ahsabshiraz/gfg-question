// Left Rotate Array bt D

#include <iostream>
using namespace std;

//{
void LRotateone(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
void LrotatebyD(int arr[], int n, int d) // Naive code
{
    for (int i = 0; i < d; i++)
    {
        LRotateone(arr, n);
    }
}
//}

//{
void leftRotate(int arr[], int n, int d) // BETTER Method
{
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[i]; // copy the first d elements in temp[]
    for (int i = d; i < n; i++)
        arr[i - d] = arr[i]; // copy remaining (n-d) elements in arr[] form starting to (n-d)
    for (int i = 0; i < d; i++)
        arr[n - d + i] = temp[i]; // copy temp[] to arr[] from (n-d) to (n)...
}
//}

//{
void reverse(int arr[], int low, int high) // swapping
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void Leftrotate(int arr[], int n, int d)//effient method using reversal
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
//}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // LrotatebyD(arr, n, 2);
    // leftRotate(arr, n, 5);
    Leftrotate(arr, n, 2);
    for (int n : arr)
        cout << n << " ";
}