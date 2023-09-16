// Converting print 1 to N in tail recursion bcz it fast
#include <iostream>
using namespace std;
void fun(int n, int k)
{
    if (n == 0)
    {
        return;
    }
    cout<<k<<" ";
    fun(n - 1, k + 1);
}
int main()
{
    int n=5;
    fun(n,1);
}