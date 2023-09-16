// Leader in an array (an element in the array which has no greater element in it's right )

#include <iostream>
using namespace std;

void PrintLeader(int arr[], int n) // NAIVE method O(n^2)
{
    int flag = false;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            cout << arr[i] << " ";
    }
}
                    
void Printleader(int arr[], int n)// Efficient method
{
    int curr_ldr = arr[n - 1];
    cout << curr_ldr << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (curr_ldr < arr[i])
        {
            curr_ldr = arr[i];
            cout << curr_ldr << " ";
        }
    }
}
int main()
{
    int arr[] = {1, 2, 10, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // PrintLeader(arr, n);
    Printleader(arr, n);
}