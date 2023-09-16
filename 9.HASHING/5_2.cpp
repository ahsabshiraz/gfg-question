// FREQUENCIES OF ARRAY ELEMENTS
// EFFICIENT SOLUTION
#include <iostream>
#include <unordered_map>
using namespace std;

void printfreq(int arr[], int n)
{
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++)
    {
        h[arr[i]]++;//increases the value of arr[i] in the hash And inserting elemets at the same time 
    }
    for (auto x : h)
        cout << x.first << " " << x.second << endl;
}
int main()
{
    int arr[] = {2, 3, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    printfreq(arr, n);
    return 0;
}