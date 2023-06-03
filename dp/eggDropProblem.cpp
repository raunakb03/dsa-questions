#include <bits/stdc++.h>
using namespace std;

int superEggDrop(int K, int N)
{
    if (N == 0 || N == 1)
        return N;
    if (K == 1)
        return N;

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
    for (int i = 0; i <= K; i++)
        dp[i][0] = 0, dp[i][1] = 1;
    for (int i = 0; i <= N; i++)
        dp[0][i] = 0, dp[1][i] = i;
    for (int i = 2; i <= K; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            int l = 1, h = j, temp = 0, ans = 1e9;
            while (l <= h)
            {
                int mid = (l + h) / 2;
                int left = dp[i - 1][mid - 1];
                int right = dp[i][j - mid];
                temp = 1 + max(left, right);
                if (left < right)
                    l = mid + 1;
                else
                    h = mid - 1;
                ans = min(ans, temp);
            }
            dp[i][j] = ans;
        }
    }
    return dp[K][N];
}