#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    ll ans = 1e9;
    for (int i = 0; i < n - m + 1; i++)
    {
        ans = min(ans, (a[i + m - 1] - a[i]));
    }
    return ans;
}