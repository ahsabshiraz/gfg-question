// GCD or HCF
#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    int res = min(a, b);
    while (res > 0)
    {
        if (a % res == 0 && b % res == 0)
        {
            return res;
        }
        res--;
    }
    return -1;
}
int main()
{
    int a = 9, b = 3;
    cout<<GCD(a, b);
    return 0;
}