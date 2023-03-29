#include <bits/stdc++.h>
using namespace std;

void f(int ind, vector<int> &vis, vector<int> adj[], vector<int> &ans)
{
    vis[ind] = 1;
    ans.push_back(ind);
    for (auto it : adj[ind])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            f(it, vis, adj, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            f(i, vis, adj, ans);
        }
    }
    return ans;
}