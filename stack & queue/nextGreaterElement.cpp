#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<ll> ans(n);
    stack<ll> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans[i] = -1;
            st.push(i);
        }
        else
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            if (!st.empty())
                ans[i] = arr[st.top()];
            else
                ans[i] = -1;
            st.push(i);
        }
    }
    return ans;
}