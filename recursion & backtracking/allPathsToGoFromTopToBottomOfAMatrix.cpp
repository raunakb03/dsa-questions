#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> allPaths;

void findPathsUtil(vector<vector<int>> maze, int m,
                   int n, int i, int j,
                   vector<int> path, int index)
{

    // If we reach the bottom of maze,
    // we can only move right
    if (i == m - 1)
    {
        for (int k = j; k < n; k++)
        {
            path[index + k - j] = maze[i][k];
        }
        allPaths.push_back(path);
        return;
    }

    // If we reach to the right most
    // corner, we can only move down
    if (j == n - 1)
    {
        for (int k = i; k < m; k++)
        {
            path[index + k - i] = maze[k][j];
        }
        allPaths.push_back(path);
        return;
    }

    path[index] = maze[i][j];
    findPathsUtil(maze, m, n, i + 1,
                  j, path, index + 1);
    findPathsUtil(maze, m, n, i, j + 1,
                  path, index + 1);
}