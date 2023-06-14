#include<bits/stdc++.h>
using namespace std;

int maxSubStr(string str)
{
    int one = 0, zero = 0;
    int cnt = 0;
    int len = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            zero++;
        else if (str[i] == '1')
            one++;

        if (one != 0 && one == zero)
        {
            len += one + zero;
            cnt++;
            one = 0;
            zero = 0;
        }
    }
    if (len != str.size())
        return -1;
    return cnt;
}