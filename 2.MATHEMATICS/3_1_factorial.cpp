// Factorial of number
#include <iostream>
using namespace std;

int factorial(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum = sum * i;
    }
    return sum;
}
int main()
{
    int n=16;
    cout<<factorial(n);
    return 0;
}  