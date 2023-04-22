#include <bits/stdc++.h>
using namespace std;

// memoization 
int f(int ind, int target, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (ind >= n)
        return 0;
    if (ind == n - 1)
    {
        if (wt[n - 1] <= target)
            return val[n - 1];
        else
            return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];
    int include = 0, notInclude = 0;
    if (target >= wt[ind])
        include += val[ind] + f(ind + 1, target - wt[ind], wt, val, n, dp);
    notInclude = f(ind + 1, target, wt, val, n, dp);

    return dp[ind][target] = max(include, notInclude);
}

// tabulation
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = 0; i <= W; i++)
    {
        if (wt[0] <= i)
        {
            dp[0][i] = val[0];
        }
    }
    for (int weight = 0; weight <= W; weight++)
    {
        for (int ind = 1; ind < n; ind++)
        {
            int include = 0, notInclude = 0;
            if (weight >= wt[ind])
                include = val[ind] + dp[ind - 1][weight - wt[ind]];
            notInclude = dp[ind - 1][weight];

            dp[ind][weight] = max(include, notInclude);
        }
    }
    return dp[n - 1][W];
}