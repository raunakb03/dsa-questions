#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftSmall[n], rightSmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = st.top() + 1;
        st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        if (st.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = st.top() - 1;
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }
    return ans;
}