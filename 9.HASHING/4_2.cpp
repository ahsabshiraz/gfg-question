// COUNT DISTINCT ELEMENTS
// EFFICIENT SOLUTION

#include <iostream>
#include <unordered_set>
using namespace std;

int countDist(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);//Here unordered_set don't allow  duplicates to get inserted
    }
    return s.size();
}

int main()
{
    int arr[] = {2, 3, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << countDist(arr, n);
    return 0;
}
