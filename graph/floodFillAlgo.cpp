#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    ans = image;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        ans[node.first][node.second] = color;
        q.pop();
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto d : dir)
        {
            int row = node.first + d.first;
            int col = node.second + d.second;
            if (row >= 0 && row < n && col >= 0 && col < m &&
                (image[row][col] == image[node.first][node.second]) && !(vis[row][col]))
            {
                vis[row][col] = 1;
                q.push({row, col});
            }
        }
    }
    return ans;
}