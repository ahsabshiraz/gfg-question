// Print N to 1
#include <iostream>
using namespace std;
void PrintNto1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    PrintNto1(n - 1);
}
int main()
{
    int n=12;
    PrintNto1(n);
}