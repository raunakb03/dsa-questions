#include<bits/stdc++.h>
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
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return NULL;
    TreeNode *ans;
    int val = 0;
    if (root1)
        val += root1->val;
    if (root2)
        val += root2->val;
    ans = new TreeNode(val);
    if (root1 && root2)
    {
        ans->left = mergeTrees(root1->left, root2->left);
        ans->right = mergeTrees(root1->right, root2->right);
    }
    if (!root1 && root2)
    {
        ans->left = mergeTrees(NULL, root2->left);
        ans->right = mergeTrees(NULL, root2->right);
    }
    if (root1 && !root2)
    {
        ans->left = mergeTrees(root1->left, NULL);
        ans->right = mergeTrees(root1->right, NULL);
    }
    return ans;
}
