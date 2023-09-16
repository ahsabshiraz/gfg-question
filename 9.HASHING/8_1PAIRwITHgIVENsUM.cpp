// PAIR WITH GIVEN SUM
// NAIVE SOLUTION

#include <iostream>
using namespace std;

bool ispair(int a[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == sum)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
   
    int n = sizeof(a) / sizeof(int);

    cout << ispair(a, n,9);
    return 0;
}