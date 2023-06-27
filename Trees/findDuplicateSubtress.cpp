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
map<string, int> mp;
string dfs(TreeNode *root, vector<TreeNode *> &res)
{
    if (root == NULL)
        return "null";
    string s = ',' + to_string(root->val) + dfs(root->left, res) + dfs(root->right, res);
    if (mp.count(s) && mp[s] == 1)
        res.push_back(root);
    mp[s]++;
    return s;
}
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    vector<TreeNode *> ans;
    dfs(root, ans);
    return ans;
}