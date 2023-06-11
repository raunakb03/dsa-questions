#include<bits/stdc++.h>
using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                st.push(i);
            }
            else if (s[st.top()] == ')')
            {
                st.push(i);
            }
            else
                st.pop();
        }
    }
    string ans = "";
    unordered_map<int, int> mp;
    while (!st.empty())
    {
        int ind = st.top();
        st.pop();
        mp[ind]++;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (!mp[i])
            ans += s[i];
    }
    return ans;
}