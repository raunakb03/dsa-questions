#include <bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int k)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int req = k - arr[i];
        if (req == arr[i])
        {
            ans += mp[arr[i]] - 1;
        }
        else
        {
            ans += mp[req];
        }
    }
    return ans % 2 ? ans / 2 + 1 : ans / 2;
}