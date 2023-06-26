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

// recursive 
TreeNode *prev = NULL;
void flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

// iterative
void flatten(TreeNode *root)
{
    if (!root)
        return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
        if (!st.empty())
            curr->right = st.top();
        curr->left = NULL;
    }
}