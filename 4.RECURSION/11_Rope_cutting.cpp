// ROPE cutting
#include <iostream>
using namespace std;
int maxpieces(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    // int res = max(maxpieces(n - a, a, b, c),
    //               maxpieces(n - b, a, b, c),
    //               maxpieces(n - c, a, b, c));
    int res = max(maxpieces(n - a, a, b, c), max(maxpieces(n - b, a, b, c), maxpieces(n - c, a, b, c)));
    if (res == -1)
        return -1;
    return res + 1;
}

int main()
{
    int n =6;
    cout << maxpieces(n, 2, 2, 3);
}