#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int factorial(int n, int r, vector<vector<int>> &dp)
{
    int k = r;
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    if (dp[n][r] != -1)
        return dp[n][r] % mod;
    return dp[n][r] = (factorial(n - 1, r - 1, dp) % mod + factorial(n - 1, r, dp) % mod) % mod;
}
int nCr(int n, int r)
{
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
    return factorial(n, r, dp) % mod;
}
