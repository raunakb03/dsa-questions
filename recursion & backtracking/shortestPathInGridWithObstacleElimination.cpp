#include <bits/stdc++.h>
using namespace std;

// dfs
int path(vector<vector<int>> &grid, int k, int r, int c, vector<vector<bool>> &visited, vector<vector<vector<int>>> &dp)
{
    int m = grid.size();
    int n = grid[0].size();
    if (r >= m || c >= n || r < 0 || c < 0 || visited[r][c])
        return 1e9;

    if (dp[r][c][k] != -1)
        return dp[r][c][k];

    if (r == 0 && c == 0)
        return dp[r][c][k] = 0;

    if (grid[r][c])
    {
        if (!k)
            return dp[r][c][k] = int(1e9);
        else
            k--;
    }

    visited[r][c] = 1;
    visited[r][c] = true;
    int top = 1 + path(grid, k, r - 1, c, visited, dp);
    int left = 1 + path(grid, k, r, c - 1, visited, dp);
    int down = 1 + path(grid, k, r + 1, c, visited, dp);
    int right = 1 + path(grid, k, r, c + 1, visited, dp);
    visited[r][c] = false;

    return dp[r][c][k] = min(top, min(left, min(right, down)));
}
int shortestPath(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    int ans = path(grid, k, m - 1, n - 1, visited, dp);
    if (ans >= m * n)
        return -1;
    return ans;
}

// bfs
int shortestPath(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, -1));
    queue<vector<int>> q;
    // x, y, currentLength, k
    q.push({0, 0, 0, k});
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        int x = t[0], y = t[1];
        if (x < 0 || x >= m || y < 0 || y >= n)
            continue;

        if (x == m - 1 && y == n - 1)
            return t[2];

        if (grid[x][y] == 1)
        {
            if (t[3] > 0)
                t[3]--;
            else
                continue;
        }
        // if k is previously visited with a k value more than now we prefer that one as we want to save k for the future
        if (visited[x][y] != -1 && visited[x][y] >= t[3])
            continue;

        visited[x][y] = t[3];
        q.push({x + 1, y, t[2] + 1, t[3]});
        q.push({x - 1, y, t[2] + 1, t[3]});
        q.push({x, y + 1, t[2] + 1, t[3]});
        q.push({x, y - 1, t[2] + 1, t[3]});
    }
    return -1;
}