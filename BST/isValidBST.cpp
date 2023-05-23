#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
typedef long long ll;
bool f(TreeNode *root, ll min, ll max)
{
    if (root == NULL)
        return true;

    if (root->val > min && root->val < max)
    {
        bool left = f(root->left, min, root->val);
        bool right = f(root->right, root->val, max);

        return left && right;
    }

    return false;
}
bool isValidBST(TreeNode *root)
{
    return f(root, -1e18, 1e18);
}