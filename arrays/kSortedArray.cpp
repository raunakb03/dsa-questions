#include <bits/stdc++.h>
using namespace std;
vector<int> nearlySorted(int arr[], int num, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int ind = K;
    while (ind >= 0)
    {
        pq.push(arr[ind--]);
    }
    ind = K + 1;
    vector<int> ans;
    int n = num;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
        if (ind < n)
            pq.push(arr[ind++]);
    }
    return ans;
}