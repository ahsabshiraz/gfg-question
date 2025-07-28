#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int matMed(int mat[][MAX], int r, int c)
{
    int min = mat[0][0], max = mat[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];

        if (mat[i][c - 1] > max)
            max = mat[i][c - 1];
    }

    int medPos = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = (min + max) / 2;
        int midPos = 0;

        for (int i = 0; i < r; ++i)
            midPos += upper_bound(mat[i], mat[i] + c, mid) - mat[i];
        if (midPos < medPos)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
//----------------------------------------------------------------------------------------------------------------
// https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/
// https://www.youtube.com/watch?v=Q9wXgdxJq48
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x)
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n)
{
    int low = INT_MAX, high = INT_MIN;

    // point low and high to right elements:
    for (int i = 0; i < m; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int r = 3, c = 5;
    int a[][MAX] = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {11, 13, 15, 17, 19}};
    cout << "Median is " << matMed(a, r, c) << endl;

    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}};
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
