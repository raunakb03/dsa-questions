#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = 1e9, left = 1e9;
    up = grid[i][j] + f(i - 1, j, grid, dp);
    left = grid[i][j] + f(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, grid, dp);
}

// tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = grid[0][0];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                int down = grid[i][j];
                if (j > 0)
                    down += dp[i][j - 1];
                else
                    down += 1e9;

                dp[i][j] = min(up, down);
            }
        }
    }
    return dp[m - 1][n - 1];
}