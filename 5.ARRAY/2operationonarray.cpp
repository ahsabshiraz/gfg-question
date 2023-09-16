// Function to find,delete and insert an element in an array

#include <iostream>
using namespace std;
int findelement(int arr[], int k, int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == k)
    //     {
    //         cout << "found ";
    //         break;
    //     }
    //     else if(i>n)
    //     {
    //         cout << "not found";
    //         break;
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int insert(int arr[], int n, int cap, int pos, int element)
{
    if (n == cap)
    {
        return n;
    }
    int idx = pos - 1;
    for (int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[idx] = element;
    return (n + 1);
}

int Delete(int arr[], int n, int element)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            break;
        }
        if (i == n) // element nor present in the array
            return n;
    }

    for (int j = i; j < n; j++)
    {
        arr[j] = arr[j + 1];
    }

    return (n - 1);
}

int main()
{
    int arr[10] = {12, 13, 14, 15, 16, 17};

    cout << findelement(arr, 13, 6) << endl; // printing the index of the element           
                                                                                    
    int res1 = insert(arr, 6, 10, 3, 55);

    for (int i = 0; i < res1; i++)
        cout << arr[i] << " ";

    cout << endl;

    int res2 = Delete(arr, 7, 17);
    for (int i = 0; i < res2; i++)
        cout << arr[i] << " ";
}