// Palindrome number
#include <iostream>
using namespace std;
bool ispalindrome(int n)
{
    int chk = n;
    int res = 0;
    while (chk != 0)
    {
        int l = chk % 10;
        res = res * 10 + l;
        chk = chk / 10;
    }
    if (res == n)
        return true;
    else
        return false;
}
int main()
{
    int m=101;
    cout<<ispalindrome(m);
    return 0;
}