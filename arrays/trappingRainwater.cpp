#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> prefix;
    vector<int> suffix(n);
    int s = height[n - 1];
    int p = height[0];
    for (int i = 0; i < n; i++)
    {
        p = max(height[i], p);
        prefix.push_back(p);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        s = max(height[i], s);
        suffix[i] = s;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (height[i] == prefix[i] || height[i] == suffix[i])
            continue;
        ans += abs(height[i] - min(suffix[i], prefix[i]));
    }
    for (auto c : prefix)
    {
        cout << c << " ";
    }
    cout << endl;
    for (auto c : suffix)
    {
        cout << c << " ";
    }
    cout << endl;
    return ans;
}