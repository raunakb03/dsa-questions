class NumMatrix
{
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        // pref[i][j]= matrix sum from 0,0 to i,j

        // filling the edges for the pref matrix
        for (int i = 0; i < n; i++)
        {
            if (i)
                pref[i][0] = pref[i - 1][0] + matrix[i][0];
            else
                pref[i][0] = matrix[i][0];
        }
        for (int i = 0; i < m; i++)
        {
            if (i)
                pref[0][i] = pref[0][i - 1] + matrix[0][i];
            else
                pref[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + matrix[i][j] - pref[i - 1][j - 1];
            }
        }
        prefix = pref;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = prefix[row2][col2];
        if (row1 - 1 >= 0)
            ans -= prefix[row1 - 1][col2];
        if (col1 - 1 >= 0)
            ans -= prefix[row2][col1 - 1];
        if (row1 - 1 >= 0 && col1 - 1 >= 0)
            ans += prefix[row1 - 1][col1 - 1];
        return ans;
    }
};