#include<bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    map<char, int> mp;
    for (auto c : s)
        mp[c]++;
    int ind1 = 0;
    int ind2 = 1;
    int n = s.size();
    string ans(n, '$');
    priority_queue<pair<int, char>> pq;
    for (auto c : mp)
    {
        pq.push({c.second, c.first});
    }
    while (!pq.empty())
    {
        int cnt = pq.top().first;
        char ch = pq.top().second;
        cout << ch << " " << cnt << endl;
        pq.pop();
        int ind = ind1;
        while (cnt--)
        {
            if (ind >= n)
                ind = ind2;
            ans[ind] = ch;
            ind += 2;
            if (ind1 < n)
                ind1 += 2;
            else
                ind2 += 2;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (ans[i] == ans[i + 1])
            return "";
    }
    return ans;
}