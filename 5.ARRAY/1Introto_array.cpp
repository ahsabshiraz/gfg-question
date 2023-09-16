#include <iostream>
#include <vector>
using namespace std;

// funtion return type for array

int *fun()
{
    int *ar2{new int[10]{2, 3, 2, 3, 23, 32, 32, 23}};
    return ar2;
}

vector<int> fun1()
{
    vector<int> vv = {123, 234, 345, 456, 567, 678};
    return vv;
}

int main()
{
    int arr[] = {10, 15, 20, 25, 30};
    int *ar = new int[100];
    vector<int> v = {12, 112, 234, 34, 213};

    for (int n : arr) //  for each loop
        cout << n << " ";
    cout << endl;

    for (int n : v) //  for each loop
        cout << n << " ";
    cout << endl;

    cout << v.size() << endl;

    vector<int> v1 = v; // copying v :(vector) element in v1 vector  using '=' operator
    for (int n : v1)
        cout << n << " ";
    cout << endl;

    int *ara{new int[10]{12, 12, 434, 325, 35}}; // initialize the element at the same time
    cout << ara[3] << "\n";

    // int n = 5;
    // int *ar1 = new int[n];
    // cout << "Enter the elements in array\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    int *h = fun();
    for (int i = 0; i < 7; i++)
        cout << h[i] << " ";
    cout << endl;

    vector<int> c = fun1();
    for (auto x : c)
        cout << x << " ";
    cout << endl;
}