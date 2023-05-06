#include <bits/stdc++.h>
using namespace std;

// T.C.: O(n+2e) where e is the number of edges

// return the total number of provinces
void dfs(int ind, vector<int> adj[], vector<int> &vis)
{
    vis[ind] = 1;
    for (auto c : adj[ind])
    {
        if (!vis[c])
        {
            dfs(c, adj, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    // fist change tha adj matrix to adj list
    int n = isConnected.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
            }
        }
    }
    // traverse using dfs algo and check how many times that function is called that
    // is the answer
    vector<int> vis(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i, adj, vis);
        }
    }
    return ans;
}