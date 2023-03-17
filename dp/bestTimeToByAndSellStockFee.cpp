// https : // leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include <bits/stdc++.h>
        using namespace std;
int maxProfit(vector<int> &prices, int fee)
{
    vector<vector<int>> dp(prices.size() + 2, vector<int>(2));
    int n = prices.size();
    for (int day = n - 1; day >= 0; day--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (!buy)
            {
                dp[day][buy] = max(-prices[day] + dp[day + 1][!buy],
                                   dp[day + 1][buy]);
            }
            else
                dp[day][buy] = max(-fee + prices[day] + dp[day + 1][!buy],
                                   dp[day + 1][buy]);
        }
    }
    return dp[0][0];
}