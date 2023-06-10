#include <bits/stdc++.h>
using namespace std;

vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
{
    map<int, int> mp;
    for (auto c : adjacentPairs)
    {
        mp[c[0]]++;
        mp[c[1]]++;
    }
    int lastInd;
    for (auto c : mp)
    {
        if (c.second == 1)
            lastInd = c.first;
    }
    mp.clear();
    vector<int> ans;
    ans.push_back(lastInd);
    map<int, vector<int>> mv;
    for (auto c : adjacentPairs)
    {
        int a = c[0];
        int b = c[1];
        mv[a].push_back(b);
        mv[b].push_back(a);
    }
    int n = adjacentPairs.size();
    mp[lastInd] = 1;
    while (n--)
    {
        vector<int> temp = mv[lastInd];
        if (temp.size() == 1)
        {
            ans.push_back(temp[0]);
            lastInd = temp[0];
        }
        else
        {
            if (mp[temp[0]] == 0)
            {
                ans.push_back(temp[0]);
                lastInd = temp[0];
            }
            else
            {
                ans.push_back(temp[1]);
                lastInd = temp[1];
            }
        }
        mp[lastInd] = 1;
    }
    return ans;
}