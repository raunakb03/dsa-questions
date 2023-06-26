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

// O(NlogN) approach
void f(vector<int> &inorder, TreeNode *root)
{
    if (root == NULL)
        return;
    f(inorder, root->left);
    inorder.push_back(root->val);
    f(inorder, root->right);
}
void solve(TreeNode *root, int val1, int val2)
{
    if (root == NULL)
        return;
    if (root->val == val1)
        root->val = val2;
    else if (root->val == val2)
        root->val = val1;
    solve(root->left, val1, val2);
    solve(root->right, val1, val2);
}
void recoverTree(TreeNode *root)
{
    vector<int> inorder;
    f(inorder, root);
    vector<int> temp = inorder;
    sort(temp.begin(), temp.end());
    int val1, val2;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] != temp[i])
        {
            val1 = inorder[i];
            val2 = temp[i];
        }
    }
    solve(root, val1, val2);
}

// O(N) approach
void f(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second)
{
    if (root == NULL)
        return;
    f(root->left, prev, first, second);
    if (prev != NULL)
    {
        if (prev->val > root->val)
        {
            if (first == NULL)
            {
                first = prev;
                second = root;
            }
            else
                second = root;
        }
    }
    prev = root;
    f(root->right, prev, first, second);
}
void recoverTree(TreeNode *root)
{
    TreeNode *prev = NULL;
    TreeNode *second = NULL;
    TreeNode *first = NULL;
    f(root, prev, first, second);
    swap(first->val, second->val);
}