// https: // leetcode.com/problems/search-a-2d-matrix/description/

// You are given an m x n integer matrix matrix with the following two properties : Each row is sorted in non - decreasing order.The first integer of each row is greater than the last integer of the previous row.Given an integer target, return true if target is in matrix or false otherwise.You must write a solution in O(log(m * n)) time complexity.

#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row;
    int n = matrix.size();
    int m = matrix[0].size();
    int sr = 0;
    int er = n - 1;
    while (sr <= er)
    {
        int mid = sr + (er - sr) / 2;
        if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target)
        {
            int s = 0, e = m - 1;
            while (s <= e)
            {
                int mid2 = s + (e - s) / 2;
                if (matrix[mid][mid2] == target)
                    return true;
                else if (matrix[mid][mid2] < target)
                    s = mid2 + 1;
                else
                    e = mid2 - 1;
            }
            return false;
        }
        else if (matrix[mid][m - 1] < target)
            sr = mid + 1;
        else
            er = mid - 1;
    }
    return false;
}