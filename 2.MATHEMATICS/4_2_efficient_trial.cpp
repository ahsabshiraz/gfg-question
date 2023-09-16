// Efficient method of trialing zeroes in factorial
#include <iostream>
using namespace std;
int counttrailzeros(int n)
{
    int res=0;
    for(int i=5;i<=n;i=i*5)// if n=15 so !15=1307674368000 zores=3 15/5=3
    {
        res=res+(n/i);
    }
    return res;
}
int main()
{
    int n=15;
    cout<<counttrailzeros(n);
    return 0;
}