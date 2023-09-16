// Median of two sorted array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double Medianoftwo(int a1[], int a2[], int n, int m) // naive
{
    int temp[n + m], i;
    for (i = 0; i < n; i++)
        temp[i] = a1[i];
    for (int j = 0; j < m; j++)
        temp[i++] = a2[j];

    sort(temp, temp + n + m);

    int size = n + m;
    if (size % 2 != 0)
    {
        return temp[size / 2];
    }
    else
    {
        return (temp[size / 2] + temp[size / 2 - 1]) / 2.00000;
    }
    return -1;
}

double Median(vector<int> &n1, vector<int> &n2) // same naive with the help of vector
{
    for (int i = 0; i < n2.size(); i++)
        n1.push_back(n2[i]);

    sort(n1.begin(), n1.end());
    if (n1.size() % 2 != 0)
        return n1[n1.size() / 2];
    else
        return (n1[n1.size() / 2] + n1[n1.size() / 2 - 1]) / 2.00000;
}
//------------------------------------------------------------------------------------------------------------------------------------------

double getMed(int a1[], int a2[], int n1, int n2) // efficient code
{
    int begin1 = 0, end1 = n1;

    while (begin1 < end1)
    {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];

        int min2 = (i2 == n2) ? INT_MAX : a2[i2];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
                return ((double)max(max1, max2) + min(min1, min2)) / 2;
            else
                return (double)max(max1, max2);
        }
        else if (max1 > min2)
            end1 = i1 - 1;
        else
            begin1 = i1 + 1;
    }
    return -1;
}

int main()
{
    int ar[] = {10, 20, 30, 40, 50};
    int n = sizeof(ar) / sizeof(ar[1]);
    int ar2[] = {5, 15, 25, 35, 45};
    int m = sizeof(ar2) / sizeof(ar2[1]);
    vector<int> a = {10, 20, 30, 40, 50};
    vector<int> b = {5, 15, 25, 35, 45};

    cout << Medianoftwo(ar, ar2, n, m) << " ";
    cout << Median(a, b) << " "; // with the vector(simple)
    cout << getMed(ar, ar2, n, m);
    return 0;
}