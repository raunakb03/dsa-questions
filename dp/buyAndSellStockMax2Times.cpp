#include <bits/stdc++.h>
using namespace std;

int f(int ind, int buy, int k,
      vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();
    if (ind == n - 1)
    {
        if (buy)
            return prices[n - 1];
        return 0;
    }

    if (k >= 2)
        return 0;

    if (ind >= n)
        return 0;

    if (dp[ind][buy][k] != -1)
        return dp[ind][buy][k];

    if (!buy)
        return dp[ind][buy][k] =
                   max(-prices[ind] + f(ind + 1, 1, k, prices, dp),
                       f(ind + 1, 0, k, prices, dp));
    else
        return dp[ind][buy][k] =
                   max(prices[ind] + f(ind + 1, 0, k + 1, prices, dp),
                       f(ind + 1, 1, k, prices, dp));
}

int maxProfit(vector<int> &Arr)
{
    int n = Arr.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {

                if (buy == 0)
                { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                            -Arr[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1)
                {
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                            Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    return dp[0][0][2];
}