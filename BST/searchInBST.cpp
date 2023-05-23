#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// recursive
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return root;

    if (root->val == val)
        return root;
    if (root->val > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// iterative
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return root;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node == NULL)
            return NULL;
        if (node->val == val)
            return node;
        if (node->val > val)
            q.push(node->left);
        else
            q.push(node->right);
    }
    return NULL;
}
