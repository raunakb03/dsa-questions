#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int cnt = 0;
    while (n)
    {
        if (n & 1)
            cnt++;
        n = n >> 1;
    }
    return cnt;
}
int minBitFlips(int start, int goal)
{
    int ele = start ^ goal;
    int ans = countSetBits(ele);
    return ans;
}