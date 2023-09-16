// Check if a String is subsequence of other

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSubSeq(string s1, string s2) // iterative
{

    int l1 = s1.length(), l2 = s2.length();
    int j = 0;
    if (l1 < l2)
        return false;
    for (int i = 0; i < l1 and j < l2; i++)
    {
        if (s1[i] == s2[j])
            j++;
    }
    if (j == l2)
        return true;
    return false;
}

bool RisSubSuq(string s1, string s2, int n, int m)
{
    if (m == 0)
        return true;
    if (n == 0)
        return false;
    if (s1[n - 1] == s2[m - 1])
        return RisSubSuq(s1, s2, n - 1, m - 1);
    else
        return RisSubSuq(s1, s2, n - 1, m);
}

int main()
{
    string s1 = "ABCDEF";
    string s2 = "ACD";
    int l1 = s1.length(), l2 = s2.length();
    cout << isSubSeq(s1, s2) << endl;
    cout << RisSubSuq(s1, s2, l1, l2);
    return 0;
}