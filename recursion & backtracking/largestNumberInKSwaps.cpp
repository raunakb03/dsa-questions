#include<bits/stdc++.h>
using namespace std;

void f(int ind, string str, int k, string &ans)
{
    int n = str.size();
    if (k == 0)
        return;
    if (ind >= n)
        return;

    char maxm = str[ind];
    for (int j = ind + 1; j < n; j++)
    {
        if (maxm < str[j])
            maxm = str[j];
    }

    if (maxm != str[ind])
        k--;

    for (int j = n - 1; j >= ind; j--)
    {
        if (str[j] == maxm)
        {
            swap(str[ind], str[j]);

            if (str.compare(ans) > 0)
                ans = str;

            f(ind + 1, str, k, ans);

            swap(str[ind], str[j]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    string ans = str;
    f(0, str, k, ans);
    return ans;
}