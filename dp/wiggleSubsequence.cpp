#include <bits/stdc++.h>
using namespace std;

// memoization
int f(int ind, vector<int> &nums, int prev, vector<vector<int>> &dp)
{
    if (ind >= nums.size())
        return 0;

    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    int include = 0, notInclude;
    if ((nums[ind] - nums[ind - 1] > 0 && prev < 0) ||
        ((nums[ind] - nums[ind - 1] < 0 && prev > 0)))
    {
        int diff = nums[ind] - nums[ind - 1];
        int newPrev;
        if (diff > 0)
            newPrev = 1;
        else
            newPrev = -1;
        include = 1 + f(ind + 1, nums, newPrev, dp);
    }

    notInclude = f(ind + 1, nums, prev, dp);

    return dp[ind][prev + 1] = max(include, notInclude);
}
int wiggleMaxLength(vector<int> &nums)
{
    if (nums.size() == 1)
        return 1;
    int prev;
    int ind = 1;
    while (ind < nums.size() && nums[ind] == nums[ind - 1])
    {
        ind++;
    }
    vector<vector<int>> dp(nums.size(), vector<int>(3, -1));
    if (ind == nums.size())
        return 1;
    int diff = nums[ind] - nums[ind - 1];
    if (diff > 0)
        prev = 1;
    else
        prev = -1;
    return 2 + f(ind + 1, nums, prev, dp);
}

// method 2
int wiggleMaxLength(vector<int> &nums)
{
    int positive = 1;
    int negative = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        int diff = nums[i] - nums[i - 1];
        if (diff < 0)
            positive = max(positive, 1 + negative);
        else if (diff > 0)
            negative = max(negative, 1 + positive);
    }

    return max(positive, negative);
}