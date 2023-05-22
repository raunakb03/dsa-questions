#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s)
{
    // idea is find the indexes of the characters that are causing trouble
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (!st.empty() && s[st.top()] == '(')
            {
                st.pop();
            }
            else
                st.push(i);
        }
        else
            st.push(i);
    }
    int ans = 0;
    int prev_ind = s.size();
    if (st.size() == 0)
        ans += s.size();
    while (!st.empty())
    {
        ans = max(ans, (prev_ind - st.top() - 1));
        prev_ind = st.top();
        st.pop();
    }
    ans = max(ans, prev_ind - 0);
    return ans;
}