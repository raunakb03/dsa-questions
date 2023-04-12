#include<bits/stdc++.h>
using namespace std;
long long f(int ind, int sum, int coins[], vector<vector<long long>> &dp, int n)
{
    if (ind >= n)
        return 0;
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    long long include = 0, notInclude = 0;
    if (coins[ind] <= sum)
        include += f(ind, sum - coins[ind], coins, dp, n);
    notInclude += f(ind + 1, sum, coins, dp, n);

    return dp[ind][sum] = include + notInclude;
}
long long int count(int coins[], int N, int sum)
{
    vector<vector<long long>> dp(N, vector<long long>(sum + 1, 0));
    for (int i = 0; i < N; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= sum; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            long long include = 0, notInclude = 0;
            if (coins[i] <= j)
            {
                include += dp[i][j - coins[i]];
            }
            notInclude = dp[i - 1][j];
            dp[i][j] = include + notInclude;
        }
    }
    return dp[N - 1][sum];
}