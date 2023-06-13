#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s1, string s2)
{
    string s = s2;
    string p = s1;
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int k = 1; k <= i; k++)
        {
            if (s[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || s[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (s[i - 1] == '*')
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}