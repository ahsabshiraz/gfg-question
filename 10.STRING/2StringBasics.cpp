#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string str = "geeksforgeeks";
    cout << str << " length-> " << str.length() << endl;
    str = str + "xyz";
    cout << str << endl;
    cout << str.substr(2, 8) << " <- substring" << endl; // substring
    cout << str.find("eek") << endl;

    string s1 = "abc";
    string s2 = "bcd";
    if (s1 == s2)
        cout << "same" << endl;
    else if (s1 < s2)
        cout << "samller" << endl;
    else
        cout << "Greater" << endl;

    string n;
    cout << "Enter your name\n";
    getline(cin, n);
    // cin>>n;

    cout << "\n Your name is " << n; // only prints frist half before space in between    instead of cin use getline(cin,string name)
    return 0;
}