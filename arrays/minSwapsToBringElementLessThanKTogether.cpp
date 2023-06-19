#include <bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            cnt++;
    }
    int greater = 0;
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (i >= cnt)
        {
            ans = min(ans, greater);
            if (arr[i - cnt] > k)
                greater--;
        }
        if (arr[i] > k)
            greater++;
    }
    ans = min(ans, greater);
    if (ans == 1e9)
        return 0;
    return ans;
}