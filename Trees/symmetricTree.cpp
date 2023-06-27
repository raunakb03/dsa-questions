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
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        string s1 = "", s2 = "";
        int size = q.size();
        auto node = q.front();
        if (node == root)
        {
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            if (size & 1)
                return false;
            int temp = size / 2;
            while (temp--)
            {
                auto frontNode = q.front();
                q.pop();
                if (frontNode == NULL)
                    s1 += '#';
                else
                {
                    s1 += to_string(frontNode->val);
                    q.push(frontNode->left);
                    q.push(frontNode->right);
                }
            }
            temp = size / 2;
            while (temp--)
            {
                auto frontNode = q.front();
                q.pop();
                if (frontNode == NULL)
                    s2 = '#' + s2;
                else
                {
                    s2 = to_string(frontNode->val) + s2;
                    q.push(frontNode->left);
                    q.push(frontNode->right);
                }
            }
            if (s1 != s2)
                return false;
        }
    }
    return true;
}