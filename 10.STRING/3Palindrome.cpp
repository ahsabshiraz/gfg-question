#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isPal(string str) // naive
{
    string rev = str;
    reverse(rev.begin(), rev.end());// reverse's the whole array 
    return (rev == str);
}

bool ispal(string &str)//efficient
{
    int begin = 0;
    int end = str.length() - 1;
    while (begin < end)
    {
        if (str[begin] != str[end])
            return false;

        begin++;
        end--;
    }
    return true;
}

int main()
{
    string str = "ABCDCBA";
    bool n = ispal(str);
    
    if (n == 1)
        cout << " Palindrome\n";
    else
        cout << "Not a palindrome\n";
    return 0;
}