#include <bits/stdc++.h>
using namespace std;
int f(int ind, int n, int sum, int coins[], vector<vector<int>> &dp)
{
    if (ind >= n)
        return 1e9;

    if (sum == 0)
        return 0;
    if (sum < 0)
        return 1e9;

    int include = 1e9, notInclude = 1e9;
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    if (sum >= coins[ind])
        include = 1 + f(ind, n, sum - coins[ind], coins, dp);

    notInclude = f(ind + 1, n, sum, coins, dp);

    return dp[ind][sum] = min(include, notInclude);
}
int minCoins(int coins[], int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    if (f(0, n, sum, coins, dp) == 1e9)
        return -1;
    return f(0, n, sum, coins, dp);
}