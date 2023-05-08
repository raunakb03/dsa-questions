#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < flights.size(); i++)
    {
        int src = flights[i][0];
        int dst = flights[i][1];
        int cost = flights[i][2];
        adj[src].push_back({dst, cost});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    while (!q.empty())
    {
        int leftK = q.front().first;
        int ind = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if (leftK > k)
            continue;

        for (auto c : adj[ind])
        {
            if (cost + c.second < dist[c.first])
            {
                dist[c.first] = cost + c.second;
                q.push({leftK + 1, {c.first, dist[c.first]}});
            }
        }
    }
    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}