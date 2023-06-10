#include<bits/stdc++.h>
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
bool isCompleteTree(TreeNode *root)
{
    if (root == NULL)
        return true;

    queue<TreeNode *> q;
    q.push(root);

    while (q.front() != NULL)
    {
        auto node = q.front();
        q.pop();

        q.push(node->left);
        q.push(node->right);
    }

    // if the queue has element in the right and not in the left then the null will come first in the queue and so it will not be removed
    // if val comes after null then it is at the right and not at the left
    while (!q.empty() && q.front() == NULL)
        q.pop();

    return q.empty();
}