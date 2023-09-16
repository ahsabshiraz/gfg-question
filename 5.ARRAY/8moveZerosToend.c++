// Move all zerose to end
#include <iostream>
using namespace std;

void MOVEzerosToend(int arr[], int n) // Naive soltion
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
}

void movetoend(int arr[], int n)//efficient code
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main()
{
    int arr[] = {10, 5, 0, 0, 8, 0, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // MOVEzerosToend(arr, n);
    // for (int n : arr)
    //     cout << n << " ";
    MOVEzerosToend(arr, n);
    for (int n : arr)
        cout << n << " ";
}