#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    for (int i = 0; i < size; i++)
    {
        int ele = arr[i];
        int target = n + ele;
        int s = 0, l = size - 1;
        while (s <= l)
        {
            int mid = s + (l - s) / 2;
            if (arr[mid] == target && mid != i)
            {
                return true;
            }
            else if (arr[mid] < target)
                s = mid + 1;
            else
                l = mid - 1;
        }
    }
    return false;
}