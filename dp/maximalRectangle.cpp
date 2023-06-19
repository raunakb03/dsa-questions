#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &histo)
{
    stack<int> st;
    int maxA = 0;
    int n = histo.size();
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i]))
        {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int ans = 0;
    vector<int> heights(matrix[0].size(), 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j]++;
        }
        ans = max(ans, f(heights));
    }
    return ans;
}