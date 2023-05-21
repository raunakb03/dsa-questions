#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int k)
{
    queue<long long int> q;
    vector<long long int> ans;

    for (int i = 0; i < k; i++)
    {
        if (A[i] < 0)
            q.push(i);
    }

    if (q.empty())
    {
        ans.push_back(0);
    }
    else
        ans.push_back(A[q.front()]);

    for (int i = k; i < N; i++)
    {
        if (!q.empty() && i - q.front() >= k)
            q.pop();

        if (A[i] < 0)
            q.push(i);

        if (q.empty())
        {
            ans.push_back(0);
        }
        else
            ans.push_back(A[q.front()]);
    }
    return ans;
}