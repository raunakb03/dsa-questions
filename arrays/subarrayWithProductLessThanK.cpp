#include<bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int n = nums.size();
    int prod = 1;
    int start = 0;
    int ans = 0;
    for (int end = 0; end < n; end++)
    {
        prod *= nums[end];
        while (prod >= k && start < n)
        {
            prod /= nums[start++];
        }
        if (prod < k)
        {
            ans += end - start + 1;
        }
    }
    return ans;
}