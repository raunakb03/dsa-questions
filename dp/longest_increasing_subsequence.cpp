#include <bits/stdc++.h>
using namespace std;

// memoization
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

// tabulation
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

// method 3
// dp[i] denotes the max length of increasing subsequence ending at index i.
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    int lastInd = 0;
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastInd = i;
        }
    }

    // getting the longest increasing subsequence
    vector<int> lis(maxi);
    lis[0] = nums[lastInd];
    int ind = 1;
    while (hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        lis[ind++] = lastInd;
    }

    reverse(lis.begin(), lis.end());
    return maxi;
}

// binary search approach
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return temp.size();
}