#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int maxDis = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > maxDis)
            return false;
        int currMax = i + nums[i];
        maxDis = max(maxDis, currMax);
    }
    if (maxDis >= n - 1)
        return true;
    return false;
}