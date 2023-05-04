#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> vis(m, 0);
    vector<int> visr(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (!vis[j])
                {
                    vis[j] = 1;
                }
                if (!visr[i])
                {
                    visr[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (visr[i] == 1)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (vis[i] == 1)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
    return;
}