#include <bits/stdc++.h>
using namespace std;

long long matrixSumQueries(int n, vector<vector<int>> &queries)
{
    int nq = queries.size();
    int row = n, col = n;
    map<int, int> r, c;
    long long ans = 0;
    for (int i = nq - 1; i >= 0; i--)
    {
        int type = queries[i][0];
        int ind = queries[i][1];
        int val = queries[i][2];
        if (type == 0)
        {
            if (r[ind] == 1)
                continue;
            r[ind] = 1;
            col--;
            ans += row * val;
        }
        else
        {
            if (c[ind] == 1)
                continue;
            c[ind] = 1;
            row--;
            ans += col * val;
        }
    }
    return ans;
}