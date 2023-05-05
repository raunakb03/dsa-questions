#include <bits/stdc++.h>
using namespace std;

// dfs method
bool f(int ind, int parent, int vis[], vector<int> adj[])
{
    vis[ind] = 1;
    for (auto c : adj[ind])
    {
        if (!vis[c])
        {
            if (f(c, ind, vis, adj) == true)
                return true;
        }
        else if (vis[c] && parent != c)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    int parent = -1;
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (f(i, parent, vis, adj) == true)
                return true;
        }
    }
    return false;
}

// bfs method
bool isCycle(int V, vector<int> adj[])
{
    int parent = -1;
    int vis[V] = {0};
    queue<pair<int, int>> q;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            q.push({i, -1});
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for (auto c : adj[node])
                {
                    if (!vis[c])
                    {
                        vis[c] = 1;
                        q.push({c, node});
                    }
                    else if (vis[c] && parent != c)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}