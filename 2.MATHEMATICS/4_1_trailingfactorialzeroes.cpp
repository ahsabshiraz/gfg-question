// trailing factorial zeroes
#include <iostream>
using namespace std;
int trailzero(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac = fac * i;
    }
    cout<<"factorial of "<<n<<" is "<<fac<<endl;
    int res = 0;
    while (fac % 10 == 0)
    {
        res++;
        fac = fac / 10;
    }
    return res;
}

int main()
{
    int n = 10;
    cout << trailzero(n);
    return 0;
}
