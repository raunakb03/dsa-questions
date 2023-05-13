// !NOTE : REPEAT

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    vector<int> temp = nums;
    sort(nums.begin(), nums.end());
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[temp[i]] = i;
    }
    int cnt = 0, f = 0;
    map<int, int> vis;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == temp[i])
        {
            vis[nums[i]] = 1;
        }
        if (!vis[nums[i]])
        {
            int ele = nums[i];
            f = 0;
            while (true)
            {
                f++;
                if (!vis[ele])
                {
                    vis[ele] = 1;
                    ele = nums[mp[ele]];
                }
                else
                    break;
            }
            f--;
            cnt += (f - 1);
        }
    }
    return cnt;
}