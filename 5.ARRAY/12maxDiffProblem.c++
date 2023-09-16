// Maximum difference b/w  arr[j]-arr[i] where j>i(index)

#include <iostream>
using namespace std;

int maxdiff(int arr[], int n) // Naive method
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res = max(res, arr[j] - arr[i]);
        }
    }
    return res;
}

int MAXDIFF(int arr[], int n) // Efficient method
{
    int res = 0;
    int min_val = arr[0];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    for (int j = 1; j < n; j++)
    {
        res=max(res,arr[j]-min_val);
        min_val=min(min_val,arr[j]);//updating minmum value
    }
    return res;
}
int main()
{
    int arr[] = {3, 10,2, 6, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxdiff(arr, n)<<endl;
    cout<<MAXDIFF(arr,n);
}