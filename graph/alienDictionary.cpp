#include <bits/stdc++.h>
using namespace std;

// T.C.: O(N*|S|+K) where |S| is the max length of the string and k is the numbe of characters

vector<int> topoSort(int n, vector<int> adj[])
{
    int indegree[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}
string findOrder(string dict[], int N, int K)
{
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string st1 = dict[i];
        string st2 = dict[i + 1];
        int length = min(st1.size(), st2.size());
        for (int j = 0; j < length; j++)
        {
            if (st1[j] != st2[j])
            {
                adj[st1[j] - 'a'].push_back(st2[j] - 'a');
                break;
            }
        }
    }
    vector<int> ans;
    ans = topoSort(K, adj);
    string st = "";
    for (auto c : ans)
    {
        st += c + 'a';
    }
    return st;
}