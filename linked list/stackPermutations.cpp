#include <bits/stdc++.h>
using namespace std;

int isStackPermutation(int n, vector<int> &arr1, vector<int> &arr2)
{
    stack<int> st;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        st.push(arr1[i]);
        while (!st.empty() && st.top() == arr2[ind])
        {
            st.pop();
            ind++;
        }
    }
    if (st.size())
        return 0;
    return 1;
}