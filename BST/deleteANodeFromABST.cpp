#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *findLastRight(TreeNode *root)
{
    if (root->right == NULL)
        return root;
    return findLastRight(root->right);
}
TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL)
        return root->right;
    if (root->right == NULL)
        return root->left;
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val == key)
        return helper(root);
    TreeNode *dummy = root;
    while (root != NULL)
    {
        if (root->val > key)
        {
            if (root->left && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}