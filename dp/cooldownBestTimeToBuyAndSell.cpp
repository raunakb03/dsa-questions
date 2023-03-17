// https : // leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve.You may complete as many transactions asyou
// like(i.e., buy one and sell one share of the stock multiple times) with thefollowing restrictions :
// After you sell your stock, you cannot buy stock on the next day(i.e., cooldown one day).Note : You may notengage in multiple transactions simultaneously(i.e., you must sell the stockbefore you buy again).

#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
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
                dp[day][buy] = max(prices[day] + dp[day + 2][!buy],
                                   dp[day + 1][buy]);
        }
    }
    return dp[0][0];
}