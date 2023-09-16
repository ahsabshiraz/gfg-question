#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sol(int arr[], int n)// gfg code
{
          int dp[n][n];
          for (int i = 0; i < n - 1; i++)
                    dp[i][i + 1] = max(arr[i], arr[i + 1]);
          for (int gap = 3; gap < n; gap = gap + 2)
          {
                    for (int i = 0; i + gap < n; i++)
                    {
                              int j = i + gap;
                              // cout<<arr[j]<<endl;
                              cout << endl
                                   << "dp[" << i << "][" << j << "] = max(" << arr[i] << " + min(" << dp[i + 2][j] << "," << dp[i + 1][j - 1] << ")," << endl;
                              cout << "               " << arr[j] << " + min(" << dp[i + 1][j - 1] << "," << dp[i][j - 2] << "))" << endl;

                              dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                                             arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));

                              cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                    }
          }
          return dp[0][n - 1];
}

int sol1(int arr[], int n)//pepcoding YT code
{
          int dp[n][n];
          // for (int i = 0; i < n - 1; i++)
          //           dp[i][i + 1] = max(arr[i], arr[i + 1]);
          for (int gap = 0; gap < n; gap++)
          {
                    for (int i = 0, j = gap; j < n; i++, j++)
                    {

                              // cout<<arr[j]<<endl;
                              if (gap > 1)
                              {
                                        cout << endl
                                             << "dp[" << i << "][" << j << "] = max(" << arr[i] << " + min(" << dp[i + 2][j] << "," << dp[i + 1][j - 1] << ")," << endl;
                                        cout << "               " << arr[j] << " + min(" << dp[i + 1][j - 1] << "," << dp[i][j - 2] << "))" << endl;
                              }
                              if (gap == 0)
                                        dp[i][j] = arr[i];
                              else if (gap == 1)
                                        dp[i][j] = max(arr[i], arr[j]);
                              else
                              {
                                        dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                                                       arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
                              }

                              cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                    }
          }
          return dp[0][n - 1];
}

int main()
{
          int arr[] = {20, 5, 4, 6, 8, 3};
          int n = sizeof(arr) / sizeof(arr[0]);
          cout << sol1(arr, n);
          return 0;
}