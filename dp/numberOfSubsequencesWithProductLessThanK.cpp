#include <bits/stdc++.h>
using namespace std;

int productSubseqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    // here dp[i][j] represents number of ways to make sum i with j elements
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];

            if (arr[j - 1] <= i)
                // this means if we are include j-1th element then we need to find out the number of ways to make i/arr[j-1] sum using j-1 elements and then include j in it
                dp[i][j] = dp[i / arr[j - 1]][j - 1] + 1;
        }
    }
    return dp[k][n];
}