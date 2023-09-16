// COUNT DISTINCT ELEMENTS

#include <iostream>
using namespace std;
int countDist(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            res++;
        }
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << countDist(arr, n);
    return 0;
}
