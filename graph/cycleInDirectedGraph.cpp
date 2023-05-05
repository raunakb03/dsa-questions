#include <bits/stdc++.h>
using namespace std;

bool f(int i, int pathVis[], int vis[], vector<int> adj[])
{
    vis[i] = 1;
    pathVis[i] = 1;
    for (auto c : adj[i])
    {
        if (!vis[c])
        {
            if (f(c, pathVis, vis, adj) == true)
                return true;
        }
        else if (pathVis[c])
            return true;
    }
    pathVis[i] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int pathVis[V] = {0};
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (f(i, pathVis, vis, adj) == true)
                return true;
        }
    }
    return false;
}