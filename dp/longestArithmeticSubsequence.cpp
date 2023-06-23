// repeat this question again

#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, int diff, vector<int> &nums, unordered_map<int, int> dp[])
{
    if (ind < 0)
        return 0;

    if (dp[ind].count(diff))
        return dp[ind][diff];

    int ans = 0;
    for (int j = ind - 1; j >= 0; j--)
    {
        if (nums[ind] - nums[j] == diff)
        {
            ans = max(ans, 1 + f(j, diff, nums, dp));
        }
    }
    return dp[ind][diff] = ans;
}
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;

    unordered_map<int, int> dp[n + 1];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, 2 + f(i, nums[j] - nums[i], nums, dp));
        }
    }
    return ans;
}

// tabulation
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return n;
    int ans = 0;
    unordered_map<int, int> dp[n + 1];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[j] - nums[i];
            int cnt = 1;

            // check if answer already exists
            if (dp[j].count(diff))
                cnt = dp[j][diff];
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}