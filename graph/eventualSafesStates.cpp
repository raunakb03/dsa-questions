#include <bits/stdc++.h>
using namespace std;

// using dfs algorithm
bool dfs(int node, vector<vector<int>> &adj,
         vector<int> &vis, vector<int> &pathVis, vector<int> &check)
{
    int index = node;
    vis[index] = 1;
    pathVis[index] = 1;
    check[index] = 0;
    for (auto it : adj[index])
    {
        if (!vis[it])
        {
            if (dfs(it, adj, vis, pathVis, check) == true)
            {
                check[it] = 0;
                return true;
            }
        }
        else if (pathVis[it])
        {
            check[it] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);
    vector<int> check(n, 0);
    vector<int> safeNodes;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, graph, vis, pathVis, check);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 1)
            safeNodes.push_back(i);
    }
    return safeNodes;
}

// using bfs algo
// reverse all the edges and then find the topo sort using indegree method
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(int i=0; i<graph.size(); i++){
            for(auto c: graph[i]){
                adj[c].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto c : adj[node]){
                indegree[c]--;
                if(indegree[c]==0){
                    q.push(c);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }