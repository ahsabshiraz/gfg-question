
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

const int R = 4, C = 4;

void search(int mat[R][C], int x) // naive
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == x)
            {
                cout << "Found at (" << i << ", " << j << ")";

                return;
            }
        }
    }

    cout << "Not Found";
}

void Search(int arr[R][C], int x) // efficient
{
    int i = 0, j = C - 1;
    while (i < R && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << "Found at [" << i << "," << j << "]";
            return;
        }

        else if (arr[i][j] > x)
            j--;
        else
            i++;
    }
    cout << "NOT FOUND";
}

int main()
{
    int arr[][C] = {{10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 35, 45},
                    {32, 33, 39, 50}};

    int x = 29;

    search(arr, x);
    Search(arr,x);

    return 0;
}