int candy(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            ans[i + 1] = ans[i] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && ans[i] <= ans[i + 1])
        {
            ans[i] = ans[i + 1] + 1;
        }
    }
    int sum = 0;
    for (auto c : ans)
        sum += c;
    return sum;
}