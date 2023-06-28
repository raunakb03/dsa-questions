#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};
int f(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;
    int left = max(0, f(root->left, ans));
    int right = max(0, f(root->right, ans));

    ans = max(ans, left + right + root->val);
    return max(left, right) + root->val;
}
int maxPathSum(TreeNode *root)
{
    // max path sum
    // max from left
    int ans = INT_MIN;
    f(root, ans);
    return ans;
}