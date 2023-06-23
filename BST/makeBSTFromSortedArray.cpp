#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->val = data;
    }
};

TreeNode *f(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = f(nums, start, mid - 1);
    node->right = f(nums, mid + 1, end);

    return node;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int n = nums.size();
    return f(nums, 0, n - 1);
}