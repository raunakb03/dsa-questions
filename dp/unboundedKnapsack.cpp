#include<bits/stdc++.h>
using namespace std;

int knapSack(int n, int w, int val[], int wt[])
{
    vector<vector<int>> dp(n, vector<int>(w + 1));

    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= w; i++)
    {
        if (wt[0] <= i)
            dp[0][i] = ((int)(i / wt[0])) * val[0];
        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int include = -1e9, notInclude = -1e9;
            if (wt[i] <= j)
                include = val[i] + dp[i][j - wt[i]];
            notInclude = dp[i - 1][j];
            dp[i][j] = max(include, notInclude);
        }
    }
    return dp[n - 1][w];
}