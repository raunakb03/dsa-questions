#include <bits/stdc++.h>
using namespace std;

// T.C.: O(V+E) where v is the number of nodes and e is the edges

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = numCourses;
    vector<int> adj[numCourses];
    for (auto c : prerequisites)
    {
        adj[c[0]].push_back(c[1]);
    }
    // finding the topo sort of this
    queue<int> q;
    vector<int> topo;
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto c : adj[i])
        {
            indegree[c]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
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
            {
                q.push(c);
            }
        }
    }
    if (topo.size() == n)
        return 1;
    return 0;
}