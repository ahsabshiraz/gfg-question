#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point
{
    int x;
    int y;
};
bool myCompare(point p1, point p2)
{
    return p1.x < p2.x;
}

int main()
{
    int arr[] = {2, 5, 1, 15, 10};
    int n = sizeof(arr) / sizeof(arr[2]);

    sort(arr, arr + n); // this will sort in increasing order
    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    sort(arr, arr + n, greater<int>()); // sorts in decreasing order
    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    //---------------------------------------------------------------------------------
    vector<int> A = {2, 13, 1, 14, 5, 3};

    sort(A.begin(), A.end());
    for (auto x : A)
        cout << x << " ";
    cout << endl;

    sort(A.begin(), A.end(), greater<int>());
    for (auto x : A)
        cout << x << " ";
    cout << endl;
    //---------------------------------------------------------------------------------------------
    point ar[] = {{3, 10}, {2, 8}, {5, 4}};
    int n1 = sizeof(ar) / sizeof(ar[1]);
    sort(ar, ar + n1, myCompare);
    for (auto i : ar)
        cout << i.x << " " << i.y << endl;
}