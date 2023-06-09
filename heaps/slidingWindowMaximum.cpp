#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> pq;
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        pq.push({nums[i], i});
    }
    ans.push_back(pq.top().first);
    pair<int, int> currWindow = {0, k - 1};
    while (!pq.empty())
    {
        currWindow.first++;
        currWindow.second++;
        if (currWindow.second >= n)
            break;
        if (currWindow.second < n)
            pq.push({nums[currWindow.second], currWindow.second});

        while (true && !pq.empty())
        {
            auto topEle = pq.top();
            int index = topEle.second;
            if (index < currWindow.first)
                pq.pop();

            else
                break;
        }

        auto topEle = pq.top();
        ans.push_back(pq.top().first);
    }
    return ans;
}