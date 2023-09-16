// left most non-repeating character
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nonRepeating1(string s1) // naive
{
    for (int i = 0; i < s1.length(); i++)
    {
        bool flag = false;
        for (int j = 0; j < s1.length(); j++)
        {
            if (i != j && s1[i] == s1[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return i;
    }
    return -1;
}
//----------------------------------------
int nonRepeating2(string s1) // better
{
    int count[CHAR_MAX] = {0};
    for (int i = 0; i < s1.length(); i++)
        count[s1[i]]++;

    for (int i = 0; i < s1.length(); i++)
    {
        if (count[s1[i]] == 1)
            return i;
    }
    return -1;
}

//---------------------------------------

int nonRepeating3(string s)
{
    int index[CHAR_MAX] = {0};
    fill(index, index + CHAR_MAX, -1);

    for (int i = 0; i < s.length(); i++)
    {
        if (index[s[i]] == -1)
            index[s[i]] = i;
        else
            index[s[i]] = -2;  //marking repeating element as -2
    }
    int res = INT_MAX;
    for (int i = 0; i < s.length(); i++)
    {
        if (index[s[i]] != -2)
        {
            res = min(res, index[s[i]]);
        }
    }
    return (res == INT_MAX) ? -1 : res;
}

int main()
{
    string s = "aapllee";
    cout << nonRepeating1(s) << endl;
    cout << nonRepeating2(s) << endl;
    cout << nonRepeating3(s) << endl;

    return 0;
}