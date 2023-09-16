#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a[3];
    a[0].push_back(123);
    a[1].push_back(2);
    a[2].push_back(23);
    for (int i = 0; i < 3; i++)
        for (auto x : a[i])
            cout << x << " ";
    return 0;
}