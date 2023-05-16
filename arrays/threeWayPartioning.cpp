#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int> &array, int a, int b)
{
    int n = array.size();
    int s = 0, e = n - 1;
    for (int i = 0; i <= e;)
    {
        if (array[i] < a)
        {
            swap(array[i++], array[s++]);
        }
        else if (array[i] > b)
        {
            swap(array[i], array[e--]);
        }
        else
            i++;
    }
}