#include<bits/stdc++.h>
using namespace std;

void permute(string &s, int l, int r, set<string> &ans)
{
    if (l == r)
        ans.insert(s);
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            permute(s, l + 1, r, ans);
            swap(s[l], s[i]);
        }
    }
}
vector<string> find_permutation(string S)
{
    int n = S.size();
    set<string> ans;
    permute(S, 0, n - 1, ans);
    vector<string> result(ans.begin(), ans.end());
    return result;
}
