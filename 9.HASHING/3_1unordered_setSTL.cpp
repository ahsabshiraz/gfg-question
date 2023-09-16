#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(56);
    s.insert(43);
    s.insert(32);
    s.insert(13);
    for (auto x : s)
        cout << x << " ";
    cout << "\n";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    cout << s.size() << " ";

    //  s.clear();

    cout << s.size();

    if (s.find(10) == s.end())
        cout << "NOT FOUND";
    else
    {
        cout << "FOUND";
        return 0;
    }
    if (s.count(10)) // count function returns 1 then it is there if it returns 0 then false not present   
        cout << "FOUND";
    else
    {
        cout << "NOT FOUND";
        return 0;
    }
    auto it= s.find(56);
    s.erase(it);
    s.erase(s.begin(),s.end());
    return 0;
}
