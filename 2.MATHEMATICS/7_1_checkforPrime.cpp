// check for prime <NAIVE>
#include <iostream>
using namespace std;
int isprime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int n = 13;
    cout << isprime(n);
}