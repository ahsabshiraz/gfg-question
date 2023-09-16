// recursive factorial
#include <iostream>
using namespace std;

int Rfac(int n)
{
    if (n == 0)
        return 1;
    return Rfac(n - 1) * n;
}

int main()
{
    int n=5;
    cout<<Rfac(n);
    return 0;
}