#include<bits/stdc++.h>
using namespace std;

int findPosition(int n)
{
    int ind = -1;
    int cnt = 1;
    int totcnt = 0;
    while (n)
    {
        totcnt++;
        if (n & 1)
        {
            if (ind != -1)
                return -1;
            else
            {
                ind = totcnt;
            }
        }
        n = n >> 1;
    }
    return ind;
}