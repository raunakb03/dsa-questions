#include<bits/stdc++.h>
using namespace std;

int minvalid(string s)
{
    stack<int> st;
    for (auto it : s)
    {
        if (it == '(')
            st.push(it);
        else if (it == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(it);
        }
    }
    return st.size();
}

void solve(string s, vector<string> &ans, map<string, bool> &mpp, int removal)
{
    if (mpp[s])
        return;

    else
        mpp[s] = true;

    if (removal == 0)
    {
        int n = minvalid(s);
        if (n == 0)
            ans.push_back(s);
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        solve(left + right, ans, mpp, removal - 1);
    }
}

vector<string> removeInvalidParentheses(string s)
{
    int removal = minvalid(s);
    vector<string> ans;
    map<string, bool> mpp;
    solve(s, ans, mpp, removal);
    return ans;
}