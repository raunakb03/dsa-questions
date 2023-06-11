#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return (t == s);
}
void f(int ind, string s, int n, vector<string> temp, vector<vector<string>> &ans)
{
    if (ind == n)
    {
        int size = 0;
        for (auto c : temp)
            size += c.size();
        if (size == s.size())
            ans.push_back(temp);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (isPalindrome(s.substr(ind, i - ind + 1)))
        {
            temp.push_back(s.substr(ind, i - ind + 1));
            f(i + 1, s, n, temp, ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> temp;
    f(0, s, s.size(), temp, ans);
    return ans;
}