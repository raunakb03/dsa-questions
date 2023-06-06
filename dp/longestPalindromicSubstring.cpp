#include <bits/stdc++.h>
using namespace std;

// method 1
string f(int s, int l, string &res, string &st)
{
    int n = st.size();
    while (s >= 0 && l < n)
    {
        if (st[s] != st[l])
            break;
        s--;
        l++;
    }
    return st.substr(s + 1, l - s - 1);
}
string longestPalindrome(string s)
{
    int n = s.size();
    string res = "";
    for (int i = 0; i < n; i++)
    {
        // start from same index for odd length palindrome
        string odd = f(i, i, res, s);
        if (res.size() < odd.size())
        {
            res = odd;
        }
        // start from different index for even length palindrome
        string even = f(i, i + 1, res, s);
        if (res.size() < even.size())
        {
            res = even;
        }
    }
    return res;
}

// method 2
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int maxLength = 0;
    string ans = "";
    for (int diff = 0; diff < n; diff++)
    {
        for (int i = 0, j = i + diff; j < n; i++, j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (diff == 1)
                dp[i][j] = s[i] == s[j] ? 2 : 0;
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            if (dp[i][j])
            {
                if (j - i + 1 > maxLength)
                {
                    ans = s.substr(i, j - i + 1);
                    maxLength = j - i + 1;
                }
            }
        }
    }
    return ans;
}