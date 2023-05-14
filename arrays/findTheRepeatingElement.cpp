#include <bits/stdc++.h>
using namespace std;

// Logic 1 without modifying the array with O(nlogn) space complexity
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (fast != slow);

    fast = nums[0];
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

// Logic 2 modifying the array with O(n) space complexity
int findDuplicate(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i])] < 0)
            return abs(nums[i]);
        int index = abs(nums[i]);
        nums[abs(nums[i])] = -nums[abs(nums[i])];
    }
    return nums[0];
}