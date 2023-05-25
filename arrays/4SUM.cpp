#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        for (int j = i + 1; j < nums.size(); j++)
        {
            int ele = nums[j];
            int first = nums[i];
            int second = nums[j];
            int s = j + 1, l = nums.size() - 1;
            long long find = (long long)target - (long long)nums[i] - (long long)nums[j];
            while (s < l)
            {
                int ele1 = nums[s];
                int ele2 = nums[l];
                if (nums[s] + nums[l] == find)
                {
                    ans.push_back({first, second, nums[s], nums[l]});
                    s++;
                    l--;
                    while (s < nums.size() && nums[s] == ele1)
                        s++;
                    while (l >= 0 && nums[l] == ele2)
                        l--;
                }
                else if (nums[s] + nums[l] < find)
                {
                    s++;
                }
                else
                {
                    l--;
                }
            }
            while (j < nums.size() && nums[j] == ele)
            {
                j++;
            }
            j--;
        }
        while (i < nums.size() && nums[i] == ele)
        {
            i++;
        }
        i--;
    }
    return ans;
}