#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long minCost(long long arr[], long long n)
{
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq(arr, arr + n);
    while (!pq.empty())
    {
        ll ele1 = pq.top();
        pq.pop();
        if (pq.empty())
            return ans;
        ll ele2 = pq.top();
        pq.pop();
        ans += ele1 + ele2;
        pq.push(ele1 + ele2);
    }
}