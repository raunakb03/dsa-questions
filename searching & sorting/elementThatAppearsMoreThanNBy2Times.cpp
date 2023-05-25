#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int cnt = 0, ele;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt == 0)
        {
            cnt++;
            ele = nums[i];
        }
        else if (ele == nums[i])
            cnt++;
        else
            cnt--;
    }
    cnt = 0;
    for (auto c : nums)
        c == ele &&cnt++;
    if (cnt > nums.size() / 2)
        return ele;
    return -1;
}