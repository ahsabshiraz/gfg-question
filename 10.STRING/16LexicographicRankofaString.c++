#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int lexRank(string &str)
{
    int res = 1;
    int n = str.length();
    int mul = fact(n);
    int count[CHAR] = {0};
    for (int i = 0; i < n; i++)
        count[str[i]]++;
    for (int i = 1; i < CHAR; i++)
        count[i] += count[i - 1];
    for (int i = 0; i < n - 1; i++)
    {
        mul = mul / (n - i);
        res = res + count[str[i] - 1] * mul;
        for (int j = str[i]; j < CHAR; j++)
            count[j]--;
    }
    return res;
}

int sortedPermutationRank(string str) // https://www.youtube.com/watch?v=uUN8fVPrJn0
{
    int n = str.length();
    long fact[26];
    int arr[256] = {};
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 26; i++)
        fact[i] = i * fact[i - 1];

    for (int i = 0; i < n; i++)
        arr[str[i]]++;

    int numberOfletterSmaller = 0;
    int output = 0;
    for (int i = 0; i < n; i++)
    {
        numberOfletterSmaller = 0;
        for (int j = 0; j < 256; j++)
        {
            if (str[i] == j)
                break;
            if (arr[j])
                numberOfletterSmaller++;
        }
        arr[str[i]] = 0;
        output += numberOfletterSmaller * fact[n - 1 - i];
    }
    return output + 1;
}
int main()
{
    string str = "ibytes";
    cout << lexRank(str) << endl;
    cout << sortedPermutationRank(str); // https://www.youtube.com/watch?v=uUN8fVPrJn0
    return 0;
}