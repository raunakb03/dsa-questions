#include <bits/stdc++.h>
using namespace std;
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int nlast = n - 1;
    int mfirst = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[nlast--], arr2[mfirst++]);
            j++;
        }
        else
        {
            i++;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}