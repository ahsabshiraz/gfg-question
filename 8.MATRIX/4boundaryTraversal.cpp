// Boundary Traversal
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Btraversal(vector<vector<int>> &A)
{
    int r = A.size();
    int c = A[0].size();
    if (r== 1)
        for (int i = 0; i <c ; i++)
            cout
                << A[0][i] << " ";
    if (c== 1)
        for (int i = 0; i <r ; i++)
            cout << A[i][0] << " ";
    else
    {
        for (int i = 0; i <c ; i++)
            cout << A[0][i] << " ";

        for (int i = 1; i <r ; i++)
            cout << A[i][c-1] << " ";

        for (int i = c-2; i >= 0; i--)
            cout << A[r - 1][i] << " ";

        for (int i = r-2; i >= 1; i--)
            cout << A[i][0] << " ";
    }
}

int main()
{
    vector<vector<int>> a{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    Btraversal(a);

    return 0;
}