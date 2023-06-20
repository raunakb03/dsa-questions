#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &prices, int k, int buy, int dp[1000][101][2])
{

    if (!k)
        return 0;
    if (ind >= prices.size())
        return 0;

    if (dp[ind][k][buy] != -1)
        return dp[ind][k][buy];

    if (!buy)
    {
        return dp[ind][k][buy] = max(-prices[ind] + f(ind + 1, prices, k, !buy, dp),
                                     f(ind + 1, prices, k, buy, dp));
    }

    else
    {
        return dp[ind][k][buy] = max(prices[ind] + f(ind + 1, prices, k - 1, 0, dp),
                                     f(ind + 1, prices, k, buy, dp));
    }
}
int maxProfit(int k, vector<int> &prices)
{
    int dp[1000][101][2];
    memset(dp, -1, sizeof(dp));
    return f(0, prices, k, 0, dp);
}

// tabulation
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int cap = 1; cap <= k; cap++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                if (buy == 0)
                {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                            -prices[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1)
                {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                            prices[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }
    return dp[0][0][k];
}