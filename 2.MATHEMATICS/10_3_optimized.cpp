// Print all the prime no smaller than n (OPTIMIZED)
#include <iostream>
#include <vector>
using namespace std;

void printPRime(int n)
{
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i* i; j <= n; j = j + i)
            {
                isprime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
            cout << i << " ";
    }
}
int main()
{
    int n=15;
    printPRime(n);
}