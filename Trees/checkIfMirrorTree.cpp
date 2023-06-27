#include <bits/stdc++.h>
using namespace std;

int checkMirrorTree(int M, int N, int u1[],
                    int v1[], int u2[], int v2[])
{
    // Map to store nodes of the tree
    unordered_map<int, stack<int>> mp;

    // Traverse first tree nodes
    for (int i = 0; i < N; i++)
    {
        mp[u1[i]].push(v1[i]);
    }

    // Traverse second tree nodes
    for (int i = 0; i < N; i++)
    {
        if (mp[u2[i]].top() != v2[i])
            return 0;
        mp[u2[i]].pop();
    }

    return 1;
}