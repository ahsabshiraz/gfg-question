// Recursion practise part_2
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n == 1)
        return;
    fun(n / 2);
    cout << n % 2 << " ";
}
int main()
{
    int n = 7;
    fun(n);
}