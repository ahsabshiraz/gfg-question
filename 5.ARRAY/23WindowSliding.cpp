// Window sliding Techenique
#include <iostream>
using namespace std;
// Q> Given an array of integer and a number k ,find the maximum sum of k consecutive element.
int max_Sum(int arr[], int n, int k) //(naive)
{
    int maxsum = INT_MIN;
    int Sum;
    for (int i = 0; i + k - 1 < n; i++)
    {
        Sum = 0;
        for (int j = 0; j < k; j++)
        {
            Sum += arr[i + j];
        }
        maxsum = max(Sum, maxsum);
    }
    return maxsum;
}
// Maximum Sum of K Consecutive elements(Efficient(window sliding)
int maxSum(int arr[], int n, int k)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];
    int max_sum = curr_sum;
    for (int i = k; i < n; i++)
    {
        curr_sum += (arr[i] - arr[i - k]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

// Q> given an unsorted array with non-negative elements find a sub array with given sum
bool subArraysum(int arr[], int n, int given_sum) // naive
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == given_sum)
                return true;
        }
    }
    return false;
}

int subArraySum1(int arr[], int n, int sum)//efficient
{
    /* Initialize curr_sum as value of first element
    and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
    sum, then remove starting element */
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && start < i - 1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum)
        {
            printf("Sum found between indexes %d and %d", start, i - 1);
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }

    // If we reach here, then no subarray
    printf("No subarray found");
    return 0;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << max_Sum(arr, n, 3);
    cout<<endl;
   subArraySum1(arr,n,45);
    return 0;
}