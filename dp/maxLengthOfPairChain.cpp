#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int prev, vector<vector<int>> &pairs, vector<vector<int>> &dp)
{

    if (ind == pairs.size())
        return 0;

    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];

    int include = 0, notInclude = 0;
    if (prev == -1 || pairs[ind][0] > pairs[prev][1])
        include = 1 + f(ind + 1, ind, pairs, dp);

    notInclude = f(ind + 1, prev, pairs, dp);

    return dp[ind][prev + 1] = max(include, notInclude);
}
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    int n = pairs.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(0, -1, pairs, dp);
}

// tabulation
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    int n = pairs.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            int include = 0, notInclude = 0;
            if (prev == -1 || pairs[prev][1] < pairs[i][0])
                include = 1 + dp[i + 1][i + 1];
            notInclude = dp[i + 1][prev + 1];
            dp[i][prev + 1] = max(include, notInclude);
        }
    }

    return dp[0][0];
}