// Efficient ALL divisor of a NUMBER(it does not print in order)
#include <iostream>
using namespace std;
void allD(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i)
                cout << n / i<<" ";
        }

    }
}
int main()
{
    int n=4;
    allD(n);
}