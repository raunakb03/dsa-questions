#include <bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A)
{
    string ans = "";
    // queue will contain all the non repeating characters
    queue<char> q;
    int cnt[26] = {0};
    for (auto c : A)
    {
        cnt[c - 'a']++;
        q.push(c);
        char ch = q.front();
        while (cnt[ch - 'a'] != 1 && !q.empty())
        {
            q.pop();
            ch = q.front();
        }
        if (q.empty())
            ans += '#';
        else
            ans += q.front();
    }
    return ans;
}