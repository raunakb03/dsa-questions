#include <bits/stdc++.h>
using namespace std;

// tabulation
int f(int ind, vector<int> &num, int k, vector<int> &dp)
{
    int n = num.size();
    if (ind == n)
        return 0;
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    if (dp[ind] != -1)
        return dp[ind];
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}

// memoization
int maxSumAfterPartitioning(vector<int> &num, int k)
{
    vector<int> dp(num.size() + 1, 0);
    int n = num.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = i; j < min(i + k, n); j++)
        {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[i] = maxAns;
    }
    return dp[0];
}