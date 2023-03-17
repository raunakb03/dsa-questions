// https : // leetcode.com/problems/house-robber-ii

// You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed.All houses at this place are arranged in a circle.That means the first house is the neighbor of the last one.Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police.

#include<bits/stdc++.h>
    using namespace std;
int f(int ind, int n, vector<int> &nums, vector<int> &dp)
{
    if (ind >= n - 1)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    return dp[ind] = max(nums[ind] + f(ind + 2, n, nums, dp), f(ind + 1, n, nums, dp));
}
int f1(int ind, int n, vector<int> &nums, vector<int> &dp)
{
    if (ind >= n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    return dp[ind] = max(nums[ind] + f1(ind + 2, n, nums, dp), f1(ind + 1, n, nums, dp));
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (nums.size() == 1)
        return nums[0];
    vector<int> dp1(n, -1);
    vector<int> dp2(n, -1);
    return max(f(0, n, nums, dp1), f1(1, n, nums, dp2));
}