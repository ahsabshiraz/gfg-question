// Printing recursively GFG :)
#include <iostream>
using namespace std;
void PrintRecursive(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "GFG ";
    PrintRecursive(n - 1);
}
int main()
{
    int n = 12;
    PrintRecursive(n);
    return 0;
}
