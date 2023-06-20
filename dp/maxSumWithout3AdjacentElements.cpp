#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &a, int conc, vector<vector<int>> &dp)
{
    if (ind >= a.size())
        return 0;

    if (dp[ind][conc] != -1)
        return dp[ind][conc];

    int include = 0, notInclude = 0;
    if (conc)
        include = a[ind] + f(ind + 1, a, conc - 1, dp);

    notInclude = f(ind + 1, a, 2, dp);

    return dp[ind][conc] = max(include, notInclude);
}
int findMaxSum(vector<int> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            if (j == 2)
            {
                dp[i][j] = dp[i + 1][0];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j + 1] + a[i], dp[i + 1][0]);
            }
        }
    }
    return dp[0][0];
}