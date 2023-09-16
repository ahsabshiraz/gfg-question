// INTERSECTION OF UNSORTED ARRAY
// EFFICIENT SOLUTION

#include <iostream>
#include <unordered_set>
using namespace std;

int intersection(int a[], int b[], int m, int n) // efficient solution -2
{
    int res = 0;
    unordered_set<int> s1(a, a + m);
    unordered_set<int> s2(b, b + n);
    
    for (auto i=s1.begin(); i != s1.end(); i++)
    {
        if (s2.find(*i) != s2.end())
        {
            res++;
        }
    }
    return res;
}
int intersection1(int a[], int b[], int m, int n) // efficient solution -2
{
    int res = 0;
    unordered_set<int> s(a, a + m);
    for (int i = 0; i < n; i++)
    {
        if (s.find(b[i]) != s.end())
        {
            res++;
            s.erase(b[i]);
        }
    }
    return res;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 4, 5};
    int m = sizeof(a) / sizeof(int);
    int n = sizeof(b) / sizeof(int);
    cout << intersection1(a, b, m, n);
    return 0;
}