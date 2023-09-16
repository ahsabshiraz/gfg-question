// Count digits
#include <iostream>
using namespace std;
int countdigit(int n)
{
    int copy = n;
    int count = 0;
    while (copy > 0)
    {
        copy = copy / 10;
        count++;
    }
    return count;
}

int main()
{
    int n = 22343440;
    cout<<countdigit(n);
    
    return 0;
}