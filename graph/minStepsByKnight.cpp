#include<bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    int dr[] = {1, -1, 2, -2, 1, -1, 2, -2};
    int dc[] = {2, 2, -1, -1, -2, -2, 1, 1};
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {KnightPos[0] - 1, KnightPos[1] - 1}});
    vector<vector<int>> vis(N, vector<int>(N, 0));
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int dis = top.first;
        int x = top.second.first;
        int y = top.second.second;
        if (x == TargetPos[0] - 1 && y == TargetPos[1] - 1)
            return dis;
        vis[x][y] = 1;
        for (int i = 0; i < 8; i++)
        {
            int nrow = x + dr[i];
            int ncol = y + dc[i];
            if (nrow >= 0 && nrow < N && ncol >= 0 && ncol < N && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                int newDis = 1 + dis;
                q.push({newDis, {nrow, ncol}});
            }
        }
    }
    return -1;
}