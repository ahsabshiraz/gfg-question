// MAX consecutive 1's in a binary array
#include <iostream>
using namespace std;

int maxConsecutiveOnes(bool arr[], int n) // naive
{
    int count;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 1)
                count++;
            else
                break;
        }
        res = max(count, res);
    }
    return res;
}
int MaxConsecutiveOnes(bool arr[], int n) // EFFICIENT solutION
{
    int res = 0, count;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count = 0;

        else
        {
            count++;
            res = max(res, count);
        }
    }
    return res;
}

int main()
{
    bool arr[] = {0, 1, 0, 1, 0,  1, 1, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxConsecutiveOnes(arr, n) << endl;
    cout << MaxConsecutiveOnes(arr, n);
    return 0;
}