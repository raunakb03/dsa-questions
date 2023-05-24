#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
    }
};

TreeNode *f(vector<int> &preorder, int &ind, int bound)
{
    if (ind == preorder.size() || preorder[ind] > bound)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[ind++]);
    root->left = f(preorder, ind, root->val);
    root->right = f(preorder, ind, bound);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int ind = 0;
    return f(preorder, ind, INT_MAX);
}