#include <bits/stdc++.h>
using namespace std;

void patSearchinng(string &txt, string &pat)
{
    int p = pat.length();
    int t = txt.length();
    for (int i = 0; i <= p - t;)
    {
        int j;
        for (j = 0; j < t; j++)
        {
            if (pat[i + j] != txt[i])
                break;
        }
        if (j == t)
            cout << j;
        if (j == 0)
            i++;
        else
            i = (i + j - 1);
    }
}

int main()
{
    string txt = "mississippi";
    string pat = "issip";
    cout << "All index numbers where pattern found:"
         << " ";
    patSearchinng(txt, pat);

    return 0;
}