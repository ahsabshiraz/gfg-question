// MAtrix in snake pattern
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int mat[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 4; j++)
                cout << mat[i][j] << " ";
        }
        else
        {
            for (int j = 4 - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    print(arr);

    return 0;
}