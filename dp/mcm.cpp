#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, int arr[], vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        mini = dp[i][j] = min(mini, arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp));
    }
    return mini;
}
int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N - 1, arr, dp);
}

// recursive approach
int matrixMultiplication(int N, int arr[])
{
    int dp[N][N] = {0};

    for (int i = 0; i < N; i++)
        dp[i][i] = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int steps = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                mini = min(steps, mini);
            }

            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}