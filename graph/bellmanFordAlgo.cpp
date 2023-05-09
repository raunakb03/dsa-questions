#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int dis = it[2];
            if (dist[u] != 1e8 && dist[u] + dis < dist[v])
                dist[v] = dis + dist[u];
        }
    }

    for (auto it : edges)
        if (dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]])
            return {-1};
    return dist;
}