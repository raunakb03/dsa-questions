// https : // leetcode.com/problems/find-the-duplicate-number/description/
// 15/3/2023

// Given an array of integers nums containing n + 1 integers where each integer is in the range[1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
