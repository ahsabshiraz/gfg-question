// Palindrome check
#include <iostream>
using namespace std;
bool palindrome(string &str, int start, int end)
{
    if (start >= end)
        return true;
    else
        return (str[start] == str[end]) && palindrome(str, start + 1, end - 1);
}
int main()
{
    string str= "aabaa";
   cout<< palindrome(str,0,4);
}