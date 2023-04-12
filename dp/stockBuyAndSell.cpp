// The cost of stock on each day is given in an array A[] of size N. Find all the segments of days on which you buy and sell the stock so that in between those days  for which profit can be generated

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> f(vector<int> arr, int n)
{
    vector<vector<int>> ans;
    int minPrice = arr[0];
    int buyInd = 0;
    int sellInd = -1;
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        int profit = arr[i] - minPrice;
        if (profit <= maxProfit && sellInd != -1)
        {
            ans.push_back({buyInd, sellInd});
            minPrice = arr[i];
            buyInd = i;
            maxProfit = 0;
            sellInd = -1;
        }
        if (arr[i] <= minPrice)
        {
            minPrice = arr[i];
            buyInd = i;
        }
        else
        {
            profit = arr[i] - minPrice;
            if (profit > maxProfit)
            {
                maxProfit = profit;
                sellInd = i;
            }
        }
    }
    if (maxProfit != 0)
        ans.push_back({buyInd, sellInd});
    return ans;
}

int main()
{

    vector<int> arr = {4, 2, 2, 2, 4};
    int n = 5;
    vector<vector<int>> ans = f(arr, n);
    for (auto c : ans)
    {
        for (auto it : c)
            cout << it << " ";
        cout << endl;
    }
}