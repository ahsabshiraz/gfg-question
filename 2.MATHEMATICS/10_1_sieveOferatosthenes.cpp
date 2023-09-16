// Print all the prime no smaller than n 
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % i + 2 == 0) 
            return false;
    }

    return true;
}
void printprime(int n)
{
    for (int i = 2; i <= n; i++)
    {
      if(isPrime(i))
      {
          cout<<i<<" ";
      }      
    }
}

int main()
{
    int n=135;
    printprime(n);
    return 0;
}