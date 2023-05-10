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

// using recursion
void f(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    f(root->left, ans);
    ans.push_back(root->val);
    f(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    f(root, ans);
    return ans;
}

// iterative
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> q;
    TreeNode *curr = root;
    while ((!q.empty() || curr != NULL))
    {
        if (curr != NULL)
        {
            q.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = q.top();
            q.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}