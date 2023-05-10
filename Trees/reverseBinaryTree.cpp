#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d)
    {
        this->val = d;
        left = NULL;
        right = NULL;
    }
};

// dfs
void f(TreeNode *root, TreeNode *ans)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        int left = root->left->val;
        TreeNode *leftNode = new TreeNode(left);
        ans->right = leftNode;
        f(root->left, ans->right);
    }
    if (root->right)
    {
        int right = root->right->val;
        TreeNode *rightNode = new TreeNode(right);
        ans->left = rightNode;
        f(root->right, ans->left);
    }
}
TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return root;
    TreeNode *ans = new TreeNode(root->val);
    f(root, ans);
    return ans;
}

// bfs
TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return root;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node)
        {
            q.push(node->left);
            q.push(node->right);
            swap(node->left, node->right);
        }
    }
    return root;
}