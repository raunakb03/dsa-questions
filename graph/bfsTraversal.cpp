#include <bits/stdc++.h>
using namespace std;

// T.C.: O(V+E) where v is the number of nodes and e is the edges

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vector<int> vis(V, 0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto c : adj[node])
        {
            if (!vis[c])
            {
                vis[c] = 1;
                q.push(c);
            }
        }

        ans.push_back(node);
    }
    return ans;
}