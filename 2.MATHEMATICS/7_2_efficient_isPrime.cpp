// Efficient isPrime
#include <iostream>
using namespace std;
bool isprime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++) // if i^2 is greater than n then n is prime  rather writing i< sqroot of n we have written i*i<=n 
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n=134;
    cout<<isprime(n);
}