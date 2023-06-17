#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums1, vector<int> &nums2, map<pair<int, int>, int> &mp, int currIdx, int prev)
{
    if (currIdx == nums1.size())
        return 0;
    if (mp.count({currIdx, prev}))
        return mp[{currIdx, prev}];

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    int newCurr = -1, curr = nums1[currIdx];
    if (nums1[currIdx] <= prev)
    {
        auto ind = upper_bound(nums2.begin(), nums2.end(), prev);
        if (ind == nums2.end())
            newCurr = -1;
        else
        {
            int index = ind - nums2.begin();
            newCurr = nums2[index];
        }
        if (newCurr > prev)
            x = solve(nums1, nums2, mp, currIdx + 1, newCurr);
        if (x != INT_MAX)
            x++;
    }
    else
    {
        y = solve(nums1, nums2, mp, currIdx + 1, curr);
        auto ind = upper_bound(nums2.begin(), nums2.end(), prev);
        if (ind == nums2.end())
            newCurr = -1;
        else
        {
            int index = ind - nums2.begin();
            newCurr = nums2[index];
        }
        // newCurr = getBigger(nums2, prev);
        if (newCurr > prev)
            z = solve(nums1, nums2, mp, currIdx + 1, newCurr);
        if (z != INT_MAX)
            z++;
    }
    return mp[{currIdx, prev}] = min({x, y, z});
}
int makeArrayIncreasing(vector<int> &arr1, vector<int> &nums2)
{
    sort(nums2.begin(), nums2.end());
    map<pair<int, int>, int> mp;
    int ans = solve(arr1, nums2, mp, 0, -1);
    return (ans == INT_MAX ? -1 : ans);
}
