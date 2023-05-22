#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    int k = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (ch == '(')
        {
            char top = st.top();
            st.pop();
            if (top == ')')
            {
                k = 1;
                break;
            }
            else
            {
                while (!st.empty() && st.top() != ')')
                    st.pop();
                st.pop();
            }
        }
        else
        {
            if (ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
                st.push(ch);
        }
    }
    if (k == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}