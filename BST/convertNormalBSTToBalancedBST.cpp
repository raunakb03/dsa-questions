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
void inorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}
TreeNode *inorderToBST(int s, int e, vector<int> &order)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;
    TreeNode *root = new TreeNode(order[mid]);
    root->left = inorderToBST(s, mid - 1, order);
    root->right = inorderToBST(mid + 1, e, order);

    return root;
}
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> order;
    inorder(root, order);
    for (auto c : order)
        cout << c << " ";
    return inorderToBST(0, order.size() - 1, order);
}