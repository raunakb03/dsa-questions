#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++)
        {
            int src = times[i][0];
            int dst = times[i][1];
            int cost = times[i][2];
            adj[src].push_back({dst, cost});
        }
        queue<pair<int, int>> q;
        q.push({k, 0});
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        while (!q.empty())
        {
            int ind = q.front().first;
            int cost = q.front().second;
            q.pop();
            for (auto c : adj[ind])
            {
                if (cost + c.second < dist[c.first])
                {
                    dist[c.first] = cost + c.second;
                    q.push({c.first, dist[c.first]});
                }
            }
        }
        int minTime = 0;
        for (int i = 1; i <= n; i++)
        {
            minTime = max(minTime, dist[i]);
        }
        if (minTime == 1e9)
            return -1;
        return minTime;
    }
};