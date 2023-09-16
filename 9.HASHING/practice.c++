#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

void intersection(vector<int> a, int k)
{
          unordered_map<int, int> mp;
          int n = a.size();
          for (int i = 0; i < k; i++)
                    mp[a[i]]++;
          cout << mp.size()<<" ";
          for (int i = k; i < n; i++)
          {
                    mp[a[i - k]]--;
                    if (mp[a[i - k]] == 0)
                              mp.erase(a[i - k]);
                    mp[a[i]]++;
                    cout << mp.size()<< " ";
          }
}

int main()
{
          vector<int> a = {10, 10, 5, 3, 20, 5};
          vector<int> b = {1, 2, 3, 4, 5};
          intersection(a, 4);
          return 0;
}