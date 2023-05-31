#include <bits/stdc++.h>
using namespace std;
#define m int(1e9 + 7)

long long func(int n, vector<long long> &dp)
{
    if (dp[n] != -1)
    {
        return dp[n];
    }
    if (n > 2)
        return dp[n] = (func(n - 1, dp) % m + ((n - 1) * func(n - 2, dp)) % m) % m;
    else
        return dp[n] = n;
}
int countFriendsPairings(int n)
{
    vector<long long> dp(n + 1, -1);
    return func(n, dp);
}