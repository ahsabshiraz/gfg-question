// Check for anagram
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Anagram(string s1, string s2) // naive
{
    if (s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return (s1 == s2);
}

bool anagram(string s1, string s2) // efficient
{
    if (s1.length() != s2.length())
        return false;
    int count[CHAR_MAX] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < CHAR_MAX; i++)
    {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string s1 = "listen";
    string s2 = "silent";
    cout << Anagram(s1, s2) << "\n";
    cout << anagram(s1, s2);
    return 0;
}