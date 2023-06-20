#include <bits/stdc++.h>
using namespace std;

int removals(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int ans = 1e9;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        // ith index is the min
        int target = k + arr[i];
        int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        ans = min(ans, n - 1 - index + 1 + i);
    }
    return ans;
}