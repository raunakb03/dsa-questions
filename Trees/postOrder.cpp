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

// recursive approach
void f(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    f(root->left, ans);
    f(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    f(root, ans);
    return ans;
}

// iterative approach
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    if (root)
        st.push(root);
    while (st.size())
    {
        auto p = st.top();
        // all children nodes are visited
        if (p == NULL)
        {
            st.pop();
            ans.push_back(st.top()->val);
            st.pop();
            continue;
        }
        // use NULL to mark the parent element
        st.push(NULL);
        if (p->right)
            st.push(p->right);
        if (p->left)
            st.push(p->left);
    }
    return ans;
}