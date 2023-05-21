#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                ans[i][j] = 0;
                q.push({{i, j}, 0});
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newr = x + dr[i];
            int newc = y + dc[i];
            if (newr >= 0 && newc >= 0 && newr < n && newc < m && ans[newr][newc] == -1)
            {
                ans[newr][newc] = dis + 1;
                q.push({{newr, newc}, dis + 1});
            }
        }
    }
    return ans;
}