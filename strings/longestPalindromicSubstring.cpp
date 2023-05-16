#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int bes_len = 0;
    string best_s = "";
    int n = s.size();
    // if the substring is of odd length
    for (int mid = 0; mid < n; mid++)
    {
        for (int x = 0; mid - x >= 0 && mid + x < n; x++)
        {
            if (s[mid - x] != s[mid + x])
            {
                break;
            }
            int len = 2 * x + 1;
            if (len > bes_len)
            {
                bes_len = len;
                best_s = s.substr(mid - x, len);
            }
        }
    }

    // if the substring is of even length
    for (int mid = 0; mid < n - 1; mid++)
    {
        for (int x = 0; mid - x + 1 >= 0 && mid + x < n; x++)
        {
            if (s[mid - x + 1] != s[mid + x])
            {
                break;
            }
            int len = 2 * x;
            if (len > bes_len)
            {
                bes_len = len;
                best_s = s.substr(mid - x + 1, len);
            }
        }
    }
    return best_s;
}