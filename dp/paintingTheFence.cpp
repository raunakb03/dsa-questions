#include<bits/stdc++.h>
using namespace std;

long countWays(int n, int k)
{
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    long long mod = 1000000007;

    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; i++)
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    
    // (k-1)*dp[i-1] means there are n-1 ways to paint the current fence different than the previous fence
    // (k-1)*dp[i-2] means if the (i-1)th and the ith fence would be of same color and there would k-1 colors to paint them with as this color should be different from the (i-3)th color

    return dp[n];
}