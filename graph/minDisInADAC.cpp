#include <bits/stdc++.h>
using namespace std;

// T.C.: O(V+E) where v is the number of nodes and e is the edges

// first find the topo sort and then do the distance infinity and comparison thing which is called relaxing of edges

// finding the toposort
void dfs(int ind, vector<pair<int, int>> adj[], stack<int> &st, int vis[])
{
    vis[ind] = 1;
    for (auto c : adj[ind])
    {
        int v = c.first;
        if (!vis[v])
        {
            dfs(v, adj, st, vis);
        }
    }
    st.push(ind);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    int vis[N] = {0};
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            dfs(i, adj, st, vis);
    }
    vector<int> dis(N, 1e9);
    dis[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (auto c : adj[node])
        {
            int v = c.first;
            int dist = c.second;
            if (dis[node] + dist < dis[v])
            {
                dis[v] = dis[node] + dist;
            }
        }
    }
    for (auto &c : dis)
        if (c == 1e9)
            c = -1;
    return dis;
}