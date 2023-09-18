// Reverse words in a String
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
void reverse(char s[], int st, int end)
{
    while (st <= end)
    {
        swap(s[st], s[end]);
        st++;
        end--;
    }
}

void reverseWords(char str[], int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        if (str[end] == ' ')
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }
    }
    reverse(str, start, n - 1); // we reverse last word expicitly
    reverse(str, 0, n - 1); // and now we reverse the whole array
}

int main()
{
    string s = "Welcome to Gfg yoo";
    int n = s.length();
    char str[n];
    strcpy(str, s.c_str());
    cout << "After reversing words in the string:" << endl;
    reverseWords(str, n);
    for (int i = 0; i < n; i++)
        cout << str[i];

    return 0;
}