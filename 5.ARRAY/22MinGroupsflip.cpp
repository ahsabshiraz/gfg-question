// Minimum groups flips to make same
#include <iostream>
using namespace std;
void MINgroupFLIP(int arr[], int n) // naive
{
    int i = 0;
    int res;
    int group0 = 0, group1 = 0;
    while (i < n)
    {
        if (arr[i] == 0)
        {
            group0++;
            i++;
            while (i < n)
            {
                if (arr[i] == 0)
                    i++;
                else
                    break;
            }
        }
        else if (arr[i] == 1)
        {
            group1++;
            i++;
            while (i < n)
            {
                if (arr[i] == 1)
                    i++;
                else
                    break;
            }
        }
    }
    if (group0 > group1)
        res = 1;
    else
        res = 0;

    int res1;
    if (res == 1)
        res1 = 0;
    else
        res1 = 1;

    i = 0;
    while (i < n)
    {
        if (arr[i] == res)
        {
            cout << "Fromm " << i << " to ";
            while (i < n && arr[i] == res) //&& arr[i] == arr[i + 1])
            {
                arr[i] = res1;
                i++;
            }
            cout << i - 1 << endl;
        }
        else
            i++;
    }
}

void mingroupflip(int arr[], int n)//effecient
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])// it's a differenrt group
        {
            if (arr[i] != arr[0])// it's not same group as first apprearing group
                cout << "from " << i << " to ";
            else
                cout << (i - 1) << endl;
        }
    }
    if (arr[n - 1] != arr[0])
        cout << (n - 1) << endl;
}

int main()
{
    int arr[] = {0, 1, 1, 1, 0, 0, 0, 0, 1, 0};
    int ar1[]={0, 1, 1, 1, 0, 0, 0, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    MINgroupFLIP(arr, n);
     mingroupflip(ar1,n);
    return 0;
}