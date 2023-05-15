#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    int cnt = 0;
    map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
            cnt++;
        if (mp[sum - k] != 0)
            cnt += mp[sum - k];
        mp[sum]++;
    }
    return cnt;
}