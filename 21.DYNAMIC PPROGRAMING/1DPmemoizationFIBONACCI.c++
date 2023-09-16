#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //for memset
using namespace std;
int fibo(int n) // without memoization simply recursion
{
    if (n == 1 or n == 0)
        return n;
    else
        return (fib(n - 1) + fib(n - 2));
}
//========================================================================================================================

int memo[1000];
int fib(int n)//using memoization
{
    if (memo[n] == -1)
    {
        int res;
        if (n == 1 or n == 0)
            res = n;
        else
            res = fib(n - 1) + fib(n - 2);
        memo[n] = res;
    }
    return memo[n];
}

int main()
{
    memset(memo, -1, sizeof(memo)); // void* memset( void* str, int ch, size_t n);//str[]: Pointer to the object to copy the character.
                                    // ch: The character to copy. It can be a character, a normal value as well a boolean value.
                                    //  n: Number of bytes to copy.
    cout << fib(4);
    return 0;
}
