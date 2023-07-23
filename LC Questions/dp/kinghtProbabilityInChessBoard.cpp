class Solution
{
public:
    double f(int row, int column, int n, int k, vector<vector<vector<double>>> &dp)
    {
        if (row < 0 || column < 0 || row >= n || column >= n)
            return 0;
        if (!k)
            return 1;
        if (dp[row][column][k] != -1)
            return dp[row][column][k];

        double ans = 0;
        int dr[] = {2, -2, 1, -1, 2, -2, 1, -1};
        int dc[] = {1, -1, 2, -2, -1, 1, -2, 2};
        for (int i = 0; i < 8; i++)
        {
            ans += f(row + dr[i], column + dc[i], n, k - 1, dp);
        }
        ans /= 8;
        return dp[row][column][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column)
    {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return f(row, column, n, k, dp);
    }
};