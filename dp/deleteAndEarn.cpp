// https : // leetcode.com/problems/delete-and-earn

// You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

// Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
// Return the maximum number of points you can earn by applying the above operation some number of times.

#include <bits/stdc++.h>
        using namespace std;
int f(int ind, vector<int> &nums, vector<int> &dp, unordered_map<int, int> &mp)
{
    int n = nums.size();
    if (ind >= n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    // include the current element or not include the current element
    int include = 0, notInclude = 0;
    int nextInd = ind + 1;
    int temp = nextInd;
    while (nextInd < n && nums[nextInd] == nums[ind])
    {
        nextInd++;
        temp++;
    }
    include += nums[ind] * mp[nums[ind]];
    while (nextInd < n && nums[nextInd] == nums[ind] + 1)
        nextInd++;
    include += f(nextInd, nums, dp, mp);

    notInclude = f(temp, nums, dp, mp);
    return dp[ind] = max(include, notInclude);
}
int deleteAndEarn(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), -1);
    unordered_map<int, int> mp;
    for (auto c : nums)
        mp[c]++;
    return f(0, nums, dp, mp);
}