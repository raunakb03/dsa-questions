#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    int ele1 = 0, ele2 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ele1 == nums[i])
            cnt1++;
        else if (ele2 == nums[i])
            cnt2++;
        else if (cnt1 == 0)
        {
            ele1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            ele2 = nums[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele1)
            cnt1++;
        else if (nums[i] == ele2)
            cnt2++;
    }
    int count = nums.size() / 3;
    if (cnt1 > count)
        ans.push_back(ele1);
    if (cnt2 > count)
        ans.push_back(ele2);
    return ans;
}