// Printing recursively
#include <iostream>
using namespace std;
void fun(int n)
{
    if (n == 0)
        return;
    fun(n - 1);
    cout << n << " ";
    fun(n - 1);
}
int main()
{
    int n =3;
    fun(n);
}