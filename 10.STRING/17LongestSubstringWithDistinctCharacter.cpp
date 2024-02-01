#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Naive
bool areDistinct(string str, int i, int j)
{
    vector<bool> visited(256);
    for (int k = i; k <= j; k++)
    {
        if (visited[str[k]] == true)
            return false;
        visited[str[k]] = true;
    }
    return true;
}

int longestDistinct(string str)
{
    int n = str.length(), res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
        }
    }
    return res;
}

// Better Solution
int longestDistinct1(string str)
{
    int n = str.length(), res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(256);
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]] == true)
                break;
            else
            {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
    }
}
int main()
{
    return 0;
}