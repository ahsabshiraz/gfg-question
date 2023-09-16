// FREQUENCIES OF ARRAY ELEMENTS

#include <iostream>
using namespace std;

void printfreq(int arr[], int n)
{
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
        if (flag == true)
            continue;

        int freq = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                freq++;
        }
        cout << arr[i] << " " << freq << endl;
    }
}

int main()
{
    int arr[] = {2, 3, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    printfreq(arr, n);
    return 0;
}