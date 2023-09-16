// print 1 to N
#include <iostream>
using namespace std;
void Print1toN(int n)
{
    if (n == 0)
        return;
    Print1toN(n - 1);
    cout << n << " ";
}
int main()
{
    int n = 4;
    Print1toN(n);
    return 0;
}