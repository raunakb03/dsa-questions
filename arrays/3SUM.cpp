#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int a = nums[i];
        int target = -a;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] == target)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                int ele = nums[j];
                int ele2 = nums[k];
                while (j + 1 < n && nums[j] == nums[j + 1])
                {
                    j++;
                }
                j++;
                while (k - 1 >= 0 && nums[k] == nums[k - 1])
                {
                    k--;
                }
                k--;
            }
            else if (nums[j] + nums[k] > target)
            {
                k--;
            }
            else
                j++;
        }
        while (i + 1 < n && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
    vector<vector<int>> fans;
    for (auto c : ans)
        fans.push_back(c);
    return fans;
}