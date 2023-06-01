#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int n, int x, int y, int z, vector<long long> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int a(INT_MIN), b(INT_MIN), c(INT_MIN);

    if (x <= n)
        a = f(n - x, x, y, z, dp);
    if (y <= n)
        b = f(n - y, x, y, z, dp);
    if (z <= n)
        c = f(n - z, x, y, z, dp);

    return dp[n] = 1 + max({a, b, c});
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<long long> dp(n + 1, -1);
    long long ans = f(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}

// tabulation
int findMaximum(int l, int p, int q, int r)
{
    int dp[l + 1] = {-1};
    dp[0] = 0;

    for (int i = 0; i <= l; i++)
    {

        if (dp[i] == -1)
            continue;

        if (i + p <= l)
            dp[i + p] = max(dp[i + p], dp[i] + 1);

        if (i + q <= l)
            dp[i + q] = max(dp[i + q], dp[i] + 1);

        if (i + r <= l)
            dp[i + r] = max(dp[i + r], dp[i] + 1);
    }
    if (dp[l] == -1)
    {
        dp[l] = 0;
    }
    return dp[l];
}