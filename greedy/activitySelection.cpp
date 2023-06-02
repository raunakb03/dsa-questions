#include<bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> start, vector<int> end, int n)
{
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({end[i], start[i]});
    }
    sort(vp.begin(), vp.end());
    int cnt = 1;
    int last = 0;
    for (int i = 1; i < n; i++)
    {
        int starts = vp[i].second;
        int ends = vp[i].first;
        if (starts > vp[last].first)
        {
            cnt++;
            last = i;
        }
    }
    return cnt;
}