// https: // leetcode.com/problems/merge-intervals/description/
// 16/2/2003

// Given an array of intervals where intervals[i] = [ starti, endi ], merge all overlapping intervals, and return an array of the non - overlapping intervals that cover all the intervals in the input.

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    int j = 0;
    ans.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans[j][1] >= intervals[i][0])
            ans[j][1] = max(intervals[i][1], ans[j][1]);
        else
        {
            j++;
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}