#include <bits/stdc++.h>
using namespace std;

// T.C.: O(8*N*M) as we are visiting every call and for every cell we are checking for all the adjacent nodes

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    queue<pair<pair<int, int>, int>> q;
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    q.push({{0, 0}, 0});
    if (grid[0][0] == 1)
        return -1;
    if (grid[0][0] == 0 && n == 1)
        return 1;
    int dr[] = {-1, 1, 0, 0, 1, -1, -1, 1};
    int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int dis = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            int newDist = dis + 1;
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] == 0 && newDist < dist[nrow][ncol])
            {
                dist[nrow][ncol] = newDist;
                q.push({{nrow, ncol}, newDist});
            }
        }
    }
    if (dist[n - 1][n - 1] == 1e9)
        return -1;
    return dist[n - 1][n - 1] + 1;
}