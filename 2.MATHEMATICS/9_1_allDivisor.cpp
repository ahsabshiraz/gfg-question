// ALL divisor of a NUMBER
#include <iostream>
using namespace std;
void allD(int n)
{
    if (n < 1)
    {
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i<<" ";
    }
}
int main()
{
    int n=12;
    allD(n);
}