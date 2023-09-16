// Find second largest element in the array

#include <iostream>
using namespace std;

int Largest(int arr[], int n)
{
    int ind = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[ind])
        {
            ind = i;
        }
    }

    return ind;
}
int secondLargest(int arr[], int n) // Naive approch
{
    int largest = Largest(arr, n), res = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[largest])
        {
            //if (res == -1) // in case where array is arr[]={10,10,10} same elements
             //   res = i;
             if (arr[i] > arr[res])
                res = i;
        }
    }
    return res;
}
int SecLargest(int arr[], int n)
{
    int res = -1, largest = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest]) // updates the value only when there is any greater element present than the current arr[largest]
        {
            res = largest; // here the res is being updated as the  current second largest element
            largest = i;   // here the largest is being updated as the current largest element
        }
        else if (arr[i] != arr[largest]) //  if there are dulplicates of the largest number
        {
            if (arr[i] > arr[res] || res == -1) // when there is still a second largest element present in the array || when res as not been updated yet
                res = i;
        }
    }
    return res;
}

int main()
{
    int arr[] = {2,2,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << secondLargest(arr, n) << endl;
    cout << SecLargest(arr, n);
}
