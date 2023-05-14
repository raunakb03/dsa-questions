#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int mini = intervals[0][0];
    int maxi = intervals[0][1];
    vector<vector<int>> ans;
    int k = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        k = 0;
        int first = intervals[i][0];
        int second = intervals[i][1];
        if (first >= mini && second <= maxi)
            continue;
        else if (first <= maxi && second >= maxi)
        {
            k = 1;
            maxi = second;
        }
        else if (first > maxi)
        {
            k = 1;
            ans.push_back({mini, maxi});
            mini = first;
            maxi = second;
        }
    }
    ans.push_back({mini, maxi});
    return ans;
}