#include<bits/stdc++.h>
using namespace std;

// T.C.: O(V+E) where v is the vertexes and e is the edges

// topo sort exists in dac
// kahns algorithm
void f(int ind, vector<int> adj[], stack<int> &st, int vis[])
{
    vis[ind] = 1;
    for (auto c : adj[ind])
    {
        if (!vis[c])
        {
            f(c, adj, st, vis);
        }
    }
    st.push(ind);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    int vis[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            f(i, adj, st, vis);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
// 	topo sort using bfs
vector<int> topoSort(int V, vector<int> adj[])
{
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto c : adj[i])
            indegree[c]++;
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto c : adj[node])
        {
            indegree[c]--;
            if (indegree[c] == 0)
                q.push(c);
        }
    }
    return topo;
}