#include <bits/stdc++.h>
using namespace std;

int minValue(string s, int k)
{
    int freq[26] = {0};
    for (auto c : s)
        freq[c - 'a']++;
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++)
    {
        pq.push(freq[i]);
    }
    while (k--)
    {
        int ele = pq.top();
        pq.pop();
        pq.push(--ele);
    }
    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top() * pq.top();
        pq.pop();
    }
    return ans;
}