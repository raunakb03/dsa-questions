// https: // leetcode.com/problems/arithmetic-slices

// An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
// For example, [ 1, 3, 5, 7, 9 ], [ 7, 7, 7, 7 ], and[ 3, -1, -5, -9 ] are arithmetic sequences.Given an integer array nums, return the number of arithmetic subarrays of nums.
// A subarray is a contiguous subsequence of the array.

#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return false;
    int start = 0, end = 1, sum = 0, diff;
    for (int i = 1; i < n; i++)
    {
        diff = nums[end] - nums[start];
        while (i + 1 < n && nums[i + 1] - nums[i] == diff)
        {
            i++;
            end++;
        }
        int temp = end - start + 1;
        if (temp >= 3)
        {
            sum += (temp - 2) * (temp - 2 + 1) / 2;
        }
        start = end;
        end++;
    }
    return sum;
}