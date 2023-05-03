#include <bits/stdc++.h>
using namespace std;

int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (ind == n)
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];
    int notInclude = f(ind + 1, prev_ind, nums, dp);
    int include = 0;
    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        include = 1 + f(ind + 1, ind, nums, dp);

    return dp[ind][prev_ind + 1] = max(include, notInclude);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int include = 0, notInclude = 0;
            notInclude = dp[ind + 1][prev + 1];
            if (prev == -1 || nums[ind] > nums[prev])
                include = 1 + dp[ind + 1][ind + 1];

            dp[ind][prev + 1] = max(include, notInclude);
        }
    }
    return dp[0][0];
}