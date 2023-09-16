#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> mp; // unordered_map<key,value>
    mp["hey"] = 1;
    mp["hello"] = 2;
    mp["hi"] = 3;

    // printing----------------------------------------------------------

    // for (auto x : mp)
    //     cout << x.first << " " << x.second << endl;

    for (auto i = mp.begin(); i != mp.end(); i++) // here mp.begin() provides the pointer of element to i and i.end() does the same
    {
        cout << i->first << " " << i->second << endl; // i is a pointer that why we are using (->)arrow
    }
    auto key = "hello";

    // finding element---------------------------------------------------------------------------------------------------------------------------

    if (mp.find(key) != mp.end()) // this means that we found the element we started from begin and it stoped before the end()
        cout << "found" << endl;
    else
    {
        cout << "not found";
    }

    if (mp.find(key) != mp.end())
    {
        auto temp = mp.find(key); // it provides the pointer of the key to temp
        cout << "Key is : " << temp->first << endl;
        cout << "Value is : " << temp->second << endl;
    }
    // insert----------------------------------------------------------------------------------------------------------------------------
    mp.insert({"yoooo", 4}); // mp.insert(make_pair{"yoooo", 4));
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }
    // size()====================================================================================

    cout << mp.size() << endl;

    // here we show that unordered_map does insert duplicates

    int arr[] = {2, 3, 12, 1, 14, 3, 2, 5, 3, 4, 5};
    unordered_map<int, int> mped;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (auto a : arr)
    {
        mped[a]++;
    }
    for (auto x : mped)
        cout << x.first << " " << x.second << endl;
    // for (auto i = mped.begin(); i != mped.end(); i++)
    // {
    //     cout << i->first << " " << i->second << endl;
    // }

    return 0;
}