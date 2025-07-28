// To find the minimum occurring and maximum occurring character in a given string
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int findMinMaxOccurringChar(string str)
{
    unordered_map<char, int> map;
    for (auto s : str)
        map[s]++;
    char min_char, max_char;
    int min_int = INT_MAX, max_int = INT_MIN;
    for (auto m : map)
    {
        if (max_int < m.second)
        {
            max_char = m.first;
            max_int = m.second;
        }
        if (min_int > m.second)
        {
            min_char = m.first;
            min_int = m.second;
        }
    }
    cout << max_char << " : " << max_int << endl;
    cout << min_char << " : " << min_int << endl;
}

int main()
{
    findMinMaxOccurringChar("aaabbccdffdfasv");
}

// arr[] = {3, 0, 2, 0, 4}
