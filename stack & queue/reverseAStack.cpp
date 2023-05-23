#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(num);
}
void Reverse(stack<int> &st)
{
    if (st.empty())
        return;

    int ele = st.top();
    st.pop();

    Reverse(st);

    insertAtBottom(st, ele);
}