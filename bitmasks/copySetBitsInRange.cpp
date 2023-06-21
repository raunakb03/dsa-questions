#include<bits/stdc++.h>
using namespace std;

int setSetBit(int b, int a, int l, int r)
{
    int mask = (1 << (r - l + 1));
    mask--;
    // 000010000-1 ---> 000001111
    mask = (mask << (l - 1));
    mask = (mask & a);
    b = b | mask;
    return b;
}