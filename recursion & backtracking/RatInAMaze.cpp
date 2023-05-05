#include <bits/stdc++.h>
using namespace std;

void f(int x, int y, vector<vector<int>> &m, int n, vector<string> &ans, string s)
{
    if (x < 0 or y < 0 or x >= n or y >= n or m[x][y] == 0)
        return;
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(s);
        return;
    }
    m[x][y] = 0;

    f(x + 1, y, m, n, ans, s + 'D');
    f(x - 1, y, m, n, ans, s + 'U');
    f(x, y + 1, m, n, ans, s + 'R');
    f(x, y - 1, m, n, ans, s + 'L');

    m[x][y] = 1;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    f(0, 0, m, n, ans, "");
    return ans;
}