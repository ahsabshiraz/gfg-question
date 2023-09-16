// Converting factorial into tail recusion
#include <iostream>
using namespace std;

int fac(int n, int k)
{
    if (n == 1 || n == 0)
        return k;
    else
        return fac(n - 1, k * n);
}
int main()
{

    int n=4;
    cout<<fac(n,1);
}