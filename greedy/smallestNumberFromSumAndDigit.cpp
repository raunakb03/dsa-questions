#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d)
{
    if (9 * d < s)
        return "-1";
    string ans = "";
    --s;
    int temp = d;
    while (temp)
    {
        if (temp != 1)
        {
            if (s - 9 >= 0)
            {
                ans += '9';
                s -= 9;
            }
            else
            {
                ans += (s + '0');
                s = 0;
            }
        }
        if (temp == 1)
        {
            if (s == 0)
                ans += '1';
            else
                ans += (s + 1 + '0');
        }
        temp--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}