#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
// a[][],first bracket is for colomn
{
    int ar[3][2] = {{10, 20},
                    {30, 40},
                    {50, 60}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << "\n";
    }
    //=================================================================================================================================================
    int m = 3, n = 2;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = i + j;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << " \n";
    }
    //================================================================================================================================================
    // other ways to create 2D array
    //(1.dynamically using double pointer)
    int **arr;
    int m1 = 3, n1 = 2;
    arr = new int *[m1]; // allocating a array of pointersof size[m]
    for (int i = 0; i < m1; i++)
    {
        arr[i] = new int[n1]; // each element of array of pointers piont at a array of size(n)
    }
    cout << "double pointer"
         << "\n";
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            arr[i][j] = 10;
            cout << arr[i][j] << " ";
        }
        cout << " \n";
    }
    //=================================================================================================================================================
    // 2.array of pointers
    int *arr1[m];               // array of pointers
    for (int i = 0; i < m; i++) // creating 2D-array of size (m*n)
    {
        arr1[m] = new int[n];
    }
    cout << "array of pointers"
         << "\n";
    for (int i = 0; i < m1; i++) // printing
    {
        for (int j = 0; j < n1; j++)
        {
            arr[i][j] = 11;
            cout << arr[i][j] << " ";
        }
        cout << " \n";
    }
    //=================================================================================================================================================
    // 3.Array of vector
    vector<int> arr2[m];
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            arr2[i].push_back(12);
        }
    }
    cout << "Array of vector"
         << "\n";
    for (int i = 0; i < m1; i++) // printing
    {
        for (int j = 0; j < n1; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    //=================================================================================================================================================
    // 4.Vectors of Vectors vector<vector<int>>

    vector<vector<int>> a1;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(13);
        }
        a1.push_back(v);
    }
    cout << "Vectors of Vectors vector<vector<int>>"
         << "\n";
    for (int i = 0; i < m1; i++) // printing
    {
        for (int j = 0; j < n1; j++)
        {
            cout << a1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}