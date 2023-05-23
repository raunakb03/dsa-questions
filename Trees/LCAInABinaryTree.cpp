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

// the idea is the first nodes which returns both the nodes that we have to find is the node 
TreeNode *lowestCommonAncestor(TreeNode *root,
                               TreeNode *n1, TreeNode *n2)
{
    if (root == NULL)
        return NULL;

    if (root == n1 || root == n2)
        return root;

    auto leftAns = lowestCommonAncestor(root->left, n1, n2);
    auto rightAns = lowestCommonAncestor(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
        return root;

    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;

    else
        return NULL;
}