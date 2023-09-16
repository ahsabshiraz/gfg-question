// Printing Frequencies of every element in a sorted array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printfrequence(int arr[], int n)
{
    int i = 1, frq = 1;
    while (i < n)
    {
        while (i < n && arr[i - 1] == arr[i])
        {
            frq++;
            i++;
        }
        cout << arr[i - 1] << "  " << frq << "\n";
        frq = 1;
        i++;
    }
    if (n == 1 || arr[n - 1] != arr[n - 2]) // when there is only one element in the array or
        cout << arr[n - 1] << " " << 1;     //   when last element was not the duplicate of second last element we just print 1
}

int main()
{
    int arr[] = {2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printfrequence(arr, n);
    
}