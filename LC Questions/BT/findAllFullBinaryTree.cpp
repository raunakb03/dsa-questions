class Solution
{
public:
    map<int, vector<TreeNode *>> mp;
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (!(n & 1))
            return {};
        if (n == 1)
            return {new TreeNode(0)};
        if (mp.find(n) != mp.end())
            return mp[n];
        vector<TreeNode *> ans;
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - i - 1);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mp[n] = ans;
    }
};