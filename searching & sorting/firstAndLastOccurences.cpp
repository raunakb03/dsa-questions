#include<bits/stdc++.h>
using namespace std;

// can also use lowerbound and upperbound

vector<int> searchRange(vector<int> &arr, int target)
{
    int n = arr.size();
    int x = target;
    int first = -1, last = -1;
    int s = 0, l = n - 1;

    // finding the first occurrence

    while (s <= l)
    {
        int mid = s + (l - s) / 2;
        if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else if (arr[mid] > x)
        {
            l = mid - 1;
        }
        else if (arr[mid] == x && mid - 1 >= 0 && arr[mid - 1] != x)
        {
            first = mid;
            s = mid + 1;
        }
        else if (arr[mid] == x && mid + 1 < n && arr[mid + 1] != x)
        {
            last = mid;
            l = mid - 1;
        }
        else if (arr[mid] == x && mid == 0)
        {
            first = mid;
            s = mid + 1;
        }
        else
        {
            l = mid - 1;
            if (first == -1)
                first = mid;
            if (last == -1)
                last = mid;
        }
    }

    // finding the last occurence
    s = 0;
    l = n - 1;
    while (s <= l)
    {
        int mid = s + (l - s) / 2;
        if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else if (arr[mid] > x)
        {
            l = mid - 1;
        }
        else if (arr[mid] == x && mid - 1 >= 0 && arr[mid - 1] != x)
        {
            s = mid + 1;
            first = mid;
        }
        else if (arr[mid] == x && mid + 1 < n && arr[mid + 1] != x)
        {
            l = mid - 1;
            last = mid;
        }
        else if (arr[mid] == x && mid == n - 1)
        {
            last = mid;
            l = mid - 1;
        }
        else
        {
            s = mid + 1;
            if (first == -1)
                first = mid;
            if (last == -1)
                last = mid;
        }
    }

    if (first == -1)
        first = last;
    if (last == -1)
        last = first;

    return {first, last};
}