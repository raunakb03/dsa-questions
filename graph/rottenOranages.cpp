#include <bits/stdc++.h>
using namespace std;

// T.C.: O(n*m) where e is the number of edges

int orangesRotting(vector<vector<int>> &grid)
{
    // bfs traversal as we are going one step at a time
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    int maxTime = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dur = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newr = row + dr[i];
            int newc = col + dc[i];
            if (newr < n && newc < m && newr >= 0 && newc >= 0 && !vis[newr][newc] && grid[newr][newc] == 1)
            {
                vis[newr][newc] = 1;
                q.push({{newr, newc}, dur + 1});
                maxTime = max(maxTime, dur + 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                return -1;
            }
        }
    }
    return maxTime;
}