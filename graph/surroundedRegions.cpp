#include <bits/stdc++.h>
using namespace std;

// T.C.: O(n*m)
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<char>> ans(n, vector<char>(m, 'X'));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O' && !vis[i][j])
            {
                vis[i][j] = 1;
                q.push({i, j});
                ans[i][j] = 'O';
            }
        }
    }
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newr = dr[i] + row;
            int newc = dc[i] + col;
            if (newr < n && newc < m && newr >= 0 && newc >= 0 && !vis[newr][newc] && board[newr][newc] == 'O')
            {
                vis[newr][newc] = 1;
                ans[newr][newc] = 'O';
                q.push({newr, newc});
            }
        }
    }
    board = ans;
}