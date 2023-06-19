#include <bits/stdc++.h>
using namespace std;

int minMovesToMakePalindrome(string s)
{
    int st = 0, rt = s.size() - 1;
    int ans = 0;
    while (st < rt)
    {
        int l = st, r = rt;
        while (s[l] != s[r])
            r--;
        if (l == r)
        {
            swap(s[r], s[r + 1]);
            ans++;
            continue;
        }
        else
        {
            while (r < rt)
            {
                swap(s[r], s[r + 1]);
                r++;
                ans++;
            }
        }
        st++;
        rt--;
    }
    return ans;
}