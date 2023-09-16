// print frequencies of character (in sorted order ) of string of lower case alphabets
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string s = "geeksforgeeks";
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++)
        count[s[i] - 'a']++;// hashing
    for (int i = 0; i < 26; i++)
        if (count[i] > 0)
            cout << (char)(i + 'a') << " " << count[i] << endl;
    // cout << 'g' - 'a';
    return 0;
}