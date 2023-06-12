#include<bits/stdc++.h>
using namespace std;

void f(int ind, vector<int> &candidates, int target, vector<int> temp, vector<vector<int>> &st)
{
    int n = candidates.size();
    if (target == 0)
    {
        st.push_back(temp);
        return;
    }
    if (ind == n)
        return;

    if (candidates[ind] <= target)
    {
        temp.push_back(candidates[ind]);
        f(ind, candidates, target - candidates[ind], temp, st);
        temp.pop_back();
    }
    f(ind + 1, candidates, target, temp, st);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    f(0, candidates, target, temp, ans);
    return ans;
}