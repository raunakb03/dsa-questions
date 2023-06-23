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

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    if (preorder.size() == 0)
        return NULL;

    TreeNode *root = new TreeNode(preorder[0]);
    if (preorder.size() == 1)
        return root;

    vector<int> left;
    vector<int> right;
    for (int i = 1; i < preorder.size(); i++)
    {
        if (preorder[i] > preorder[0])
            right.push_back(preorder[i]);
        else
            left.push_back(preorder[i]);
    }

    root->left = bstFromPreorder(left);
    root->right = bstFromPreorder(right);
    return root;
}