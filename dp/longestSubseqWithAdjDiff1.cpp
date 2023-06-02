#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int arr[])
{
    // dp[i] represents max len of subsequence ending at index i such that arr[i] is the last element of the subsequence
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}