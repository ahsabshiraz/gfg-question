// Efficient ALL divisor of a NUMBER( Print's in order)
#include <iostream>
using namespace std;
void allD(int n)
{
    int i = 1;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
            cout << n / i << " ";
    }
}
int main()
{
    int n = 36;
    allD(n);
}