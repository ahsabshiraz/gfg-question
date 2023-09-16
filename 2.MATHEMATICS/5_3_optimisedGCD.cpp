// optimised GCD Euclidean

#include <iostream>
using namespace std;

int GCD (int a, int b)
{
    if (b == 0)
        return a;
    else
        return (b, a % b);
}

int main()
{
    int b=10,a=15;
    cout<<GCD(a,b);
}