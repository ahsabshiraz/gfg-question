// Natural number sum using recursion
#include <iostream>
using namespace std;
int getSUM(int n)
{
    if (n == 0)
        return 0;
    else
    return n+getSUM(n-1);
}
int main()
{
    int n = 2;
    cout << getSUM(n);
}