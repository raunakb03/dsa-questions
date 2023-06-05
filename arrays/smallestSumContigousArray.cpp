#include<bits/stdc++.h>
using namespace std;

int smallestSumSubarray(vector<int> &a)
{
    int neg = 0;
    for (auto c : a)
        c < 0 && neg++;
    if (neg == 0)
    {
        int mini = 1e9;
        for (auto c : a)
            mini = min(mini, c);
        return mini;
    }
    else
    {
        int ans = 1e9;
        int curr = 0;
        for (auto c : a)
        {
            curr += c;
            if (curr > 0)
                curr = 0;
            ans = min(ans, curr);
        }
        return ans;
    }
}