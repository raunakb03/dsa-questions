#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (pq.size() == k)
        {
            if (pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        else
            pq.push(nums[i]);
    }
    return pq.top();
}