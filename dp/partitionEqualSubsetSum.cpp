#include <bits/stdc++.h>
using namespace std;

// recursion approach
bool f(int ind, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (ind >= n)
        return 0;

    if (target == 0)
        return 1;
    if (dp[ind][target] != -1)
        return dp[ind][target];
    // either include the element or exclude the element
    int include = 0, notInclude = 0;
    if (nums[ind] <= target)
        include = f(ind + 1, nums, target - nums[ind], dp);

    notInclude = f(ind + 1, nums, target, dp);

    return dp[ind][target] = include + notInclude;
}
bool canPartition(vector<int> &nums)
{
    // find a subset with sum equal to sum/2;
    int n = nums.size();
    int sum = 0;
    for (auto c : nums)
        sum += c;
    int target = sum / 2;
    if (target * 2 != sum)
        return false;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(0, nums, target, dp);
}

// iterative approach
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0LL);
    if (sum & 1)
        return 0;
    sum /= 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1));
    for (int i = 0; i < n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (nums[0] == i)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool take = false, notTake = false;
            if (nums[i] <= j)
                take = dp[i - 1][j - nums[i]];
            notTake = dp[i - 1][j];
            dp[i][j] = take || notTake;
        }
    }
    return dp[n - 1][sum];
}