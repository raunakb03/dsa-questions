#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    int temp = k;
    while (temp--)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    int size = q.size() - k;
    while (size--)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
    return q;
}