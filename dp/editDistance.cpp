#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 0;
    if (i == 0 && j != 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);
    else
        return dp[i][j] = min(1 + f(i - 1, j, s1, s2, dp),
                              min(1 + f(i, j - 1, s1, s2, dp), 1 + f(i - 1, j - 1, s1, s2, dp)));
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    if (n == 0 || m == 0)
        return m + n;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, word1, word2, dp);
}

// tabulation
int minDistance(string word1, string word2)
{
    string s1 = word1;
    string s2 = word2;
    int l1 = word1.size();
    int l2 = word2.size();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

    for (int i = 0; i <= l1; i++)
        dp[i][0] = i;
    for (int j = 0; j <= l2; j++)
        dp[0][j] = j;
    dp[0][0] = 0;

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                   min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[l1][l2];
}