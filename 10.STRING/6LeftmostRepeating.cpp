// Left most repeating character
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Leftmost1(string s) // naive
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[i] == s[j])
                return i;
        }
    }
    return -1;
}

int Leftmost2(string s) // better
{
    int count[CHAR_MAX] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i]] > 1)
            return i;
    }

    return -1;
}

int Leftmost3(string s) // efficient-1
{
    int index[256]; //= {-1};
    fill(index, index + CHAR_MAX, -1);
    int res = INT_MAX;
    for (int i = 0; i < s.length(); i++)
    {
        int fi = index[s[i]];
        if (fi == -1)
            index[s[i]] = i;
        else
            res = min(res, fi);
    }
    return (res == INT_MAX) ? -1 : res;
}

int Leftmost4(string s) // efficient-2
{
    bool visited[CHAR_MAX];
    fill(visited, visited + CHAR_MAX, false);
    int res = -1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (visited[s[i]])
            res = i;
        else
            visited[s[i]] = true;
    }
    return res;
}

int main()
{
    string s = "zxqksforgeeks";
    cout << Leftmost1(s) << endl; // naive
    cout << Leftmost2(s) << endl; // better
    cout << Leftmost3(s) << endl; // efficient-1
    cout << Leftmost4(s) << endl; // efficient-2
    return 0;
}