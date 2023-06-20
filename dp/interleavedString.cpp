#include <bits/stdc++.h>
using namespace std;

// memoization
bool f(int i, int j, int k, string s1, string s2, string s3, int dp[200][200][200])
{

    if (k == s3.size())
        return true;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    bool st1 = false, st2 = false;
    if (i < s1.size() && s1[i] == s3[k])
        st1 = f(i + 1, j, k + 1, s1, s2, s3, dp);
    if (j < s2.size() && s2[j] == s3[k])
        st2 = f(i, j + 1, k + 1, s1, s2, s3, dp);

    return dp[i][j][k] = (st1 + st2);
}
bool isInterleave(string s1, string s2, string s3)
{
    if (s3.size() != (s1.size() + s2.size()))
        return false;
    int dp[200][200][200];
    memset(dp, -1, sizeof(dp));

    return f(0, 0, 0, s1, s2, s3, dp);
}

// tabulation
bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.length();
    int m = s2.length();
    if (n + m != s3.length())
        return 0;
    bool dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                if (s2[j - 1] == s3[j - 1])
                    dp[i][j] = dp[i][j - 1];
            else if (j == 0)
                if (s1[i - 1] == s3[i - 1])
                    dp[i][j] = dp[i - 1][j];
            else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1])
                dp[i][j] = dp[i - 1][j];

            else if (s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                dp[i][j] = dp[i][j - 1];

            else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1])
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
    }
    return dp[n][m];
}