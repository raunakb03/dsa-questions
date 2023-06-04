#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &dp)
{

    if (ind == strs.size())
        return 0;

    if (dp[ind][m][n] != -1)
        return dp[ind][m][n];

    int include = 0, notInclude = 0;
    int ones = 0, zeroes = 0;
    for (auto c : strs[ind])
        c == '0' ? zeroes++ : ones++;
    if (ones <= n && zeroes <= m)
        include = 1 + f(ind + 1, m - zeroes, n - ones, strs, dp);

    notInclude = f(ind + 1, m, n, strs, dp);

    return dp[ind][m][n] = max(include, notInclude);
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    int ni = strs.size();
    vector<vector<vector<int>>> dp(ni, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return f(0, m, n, strs, dp);
}

// tabulation
int findMaxForm(vector<string> &strs, int m, int n)
{
    int ni = strs.size();
    vector<vector<vector<int>>> dp(ni + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    for (int i = ni - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int include = 0, notInclude = 0;
                int ones = 0, zeroes = 0;
                for (auto c : strs[i])
                    c == '0' ? zeroes++ : ones++;
                if (ones <= k && zeroes <= j)
                    include = 1 + dp[i + 1][j - zeroes][k - ones];

                notInclude = dp[i + 1][j][k];

                dp[i][j][k] = max(include, notInclude);
            }
        }
    }

    return dp[0][m][n];
}