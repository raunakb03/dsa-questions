#include<bits/stdc++.h>
using namespace std;

long long f(int i, int j, int arr[], int n, vector<vector<int>> &dp)
{
    if (i > j || (i >= n || j < 0))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans1 = arr[i] + min(f(i + 2, j, arr, n, dp), f(i + 1, j - 1, arr, n, dp));

    int ans2 = arr[j] + min(f(i, j - 2, arr, n, dp), f(i + 1, j - 1, arr, n, dp));

    return dp[i][j] = max(ans1, ans2);
}