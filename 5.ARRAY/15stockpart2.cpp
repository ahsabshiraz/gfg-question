#include <iostream>
using namespace std;
int maxprofit(int price[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
        {
            profit += price[i] - price[i - 1];
        }
    }
    return profit;
}

int main()
{
    int A[] = {1, 5, 3, 8, 12};
    int n = sizeof(A) / sizeof(A[0]);
    int MAX_profit = maxprofit(A, n);
    cout << MAX_profit;
    return 0;
}