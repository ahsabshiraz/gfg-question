// Printing recursively
#include <iostream>
using namespace std;
void Printnum(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    Printnum(n - 1);
    // cout << n << " ";
}
int main()
{
 
    int n=44;
    Printnum(n);
}
