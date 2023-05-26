#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    vector<int> prefix;
    for (auto c : nums)
    {
        sum += c;
        prefix.push_back(sum);
    }
    for (int i = 0; i < n; i++)
    {
        if (!i)
        {
            if (prefix[n - 1] - prefix[i] == 0)
                return 0;
        }
        else if (i == n - 1)
        {
            if (prefix[i - 1] == 0)
                return n - 1;
        }
        else
        {
            int left = prefix[i - 1];
            int right = prefix[n - 1] - prefix[i];
            if (left == right)
                return i;
        }
    }

    return -1;
}