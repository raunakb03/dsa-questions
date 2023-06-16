#include<bits/stdc++.h>
using namespace std;

int numTrees(int n)
{
    vector<int> res(n + 1, 0);
    res[1] = res[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            res[i] += res[j] * res[i - j - 1];
        }
    }
    return res[n];
}