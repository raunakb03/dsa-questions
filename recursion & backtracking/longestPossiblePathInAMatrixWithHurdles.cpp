#include <bits/stdc++.h>
using namespace std;
#define R 10
#define C 10

struct Pair
{
    bool found;
    int value;
};

Pair findLongestPathUtil(int mat[R][C], int i, int j, int x,
                         int y, bool visited[R][C])
{
    if (i == x && j == y)
    {
        Pair p = {true, 0};
        return p;
    }

    if (i < 0 || i >= R || j < 0 || j >= C || mat[i][j] == 0 || visited[i][j])
    {
        Pair p = {false, INT_MAX};
        return p;
    }

    visited[i][j] = true;

    int res = INT_MIN;

    Pair sol = findLongestPathUtil(mat, i, j - 1, x, y, visited);

    if (sol.found)
        res = max(res, sol.value);
    sol = findLongestPathUtil(mat, i, j + 1, x, y, visited);

    if (sol.found)
        res = max(res, sol.value);
    sol = findLongestPathUtil(mat, i - 1, j, x, y, visited);

    if (sol.found)
        res = max(res, sol.value);
    sol = findLongestPathUtil(mat, i + 1, j, x, y, visited);

    if (sol.found)
        res = max(res, sol.value);
    visited[i][j] = false;

    if (res != INT_MIN)
    {
        Pair p = {true, 1 + res};
        return p;
    }
    else
    {
        Pair p = {false, INT_MAX};
        return p;
    }
}
