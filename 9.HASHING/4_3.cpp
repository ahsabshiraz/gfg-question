// COUNT DISTINCT ELEMENTS
// IMPROVED EFFICIENT SOLUTION

#include <iostream>
#include <unordered_set>
using namespace std;

int countDist(int arr[], int n)
{
    unordered_set<int> s (arr,arr+n);// It simply inserts all the arrays element.not the duplicates

    return s.size();
}

int main()
{
    int arr[] = {2, 3, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << countDist(arr, n);
    return 0;
}