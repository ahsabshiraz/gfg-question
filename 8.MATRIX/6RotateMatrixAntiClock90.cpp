#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int n = 4;
void transpose(int mat[n][n]) // naive
{
    int temp[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[n - j - 1][i] = mat[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[i][j];
}
void Transpose(int mat[n][n])//efficient
{
    for (int i = 0; i < n; i++) // first covert it into the tranpose of it self
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);

    for (int i = 0; i < n; i++)    //here we are changing row
    {
        int low = 0, high = n - 1;

        while (low < high)        //reversing the column by sawping 
        {
            swap(mat[low][i], mat[high][i]);

            low++;
            high--;
        }
    }
}

int main()
{
    int arr[n][n] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    Transpose(arr);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}