// Efficient LCM
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
int LCM(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int main()
{
    int a = 4, b = 6;
    cout << LCM(a, b);
}