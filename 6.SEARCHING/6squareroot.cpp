// Square rootFloor of the given number
#include <iostream>
using namespace std;

int SqRootFloor(int x) // naive
{
    int i = 0;
    while (i * i <= x)
        i++;

    return (i - 1);
}
int SQrootFloor(int x)
{
    int low = 1, high = x, ans = -1,sq;
    while (low <= high)
    {
        int mid = (low + high) / 2;
         sq = mid * mid;
        if (mid*mid == x)
            return mid;
        else if (mid*mid > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}


int main()
{
    int x = 1009;

    cout << SqRootFloor(x) << " ";
    cout << SQrootFloor(x);
    return 0;
}