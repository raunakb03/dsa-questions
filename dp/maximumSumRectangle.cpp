#include<bits/stdc++.h>
using namespace std;

int kadanes(vector<int> &sum)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < sum.size(); i++)
    {
        max_ending_here += sum[i];
        max_so_far = max(max_so_far, max_ending_here);
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int maximumSumRectangle(int r, int c, vector<vector<int>> m)
{
    vector<int> sum(r, 0);
    int maxSum = INT_MIN;
    for (int cstart = 0; cstart < c; cstart++)
    {
        for (int i = 0; i < r; i++)
            sum[i] = 0;
        for (int cend = cstart; cend < c; cend++)
        {
            for (int row = 0; row < r; row++)
            {
                sum[row] += m[row][cend];
            }

            int curMaxSum = kadanes(sum);
            maxSum = max(maxSum, curMaxSum);
        }
    }
    return maxSum;
}