// PAIR WITH GIVEN SUM
// EFFICIENT SOLUTION

#include <iostream>
#include <unordered_set>
using namespace std;
bool ispair(int a[], int n, int sum)
{
    unordered_set<int> h;
    
    for (int i = 0; i < n; i++)
    {
        if (h.find(sum - a[i]) != h.end())
        {
            return true;
        }
        else{
            h.insert(a[i]);
        }
    }
    return false;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    int n = sizeof(a) / sizeof(int);

    cout << ispair(a, n, 9);
    return 0;
}