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

vector<int> levelOrder(Node *node)
{
    if (node == NULL)
        return {};
    queue<Node *> q;
    q.push(node);
    vector<int> ans;
    while (!q.empty())
    {
        auto root = q.front();
        q.pop();
        ans.push_back(root->data);
        if (root->left)
        {
            q.push(root->left);
        }
        if (root->right)
        {
            q.push(root->right);
        }
    }
    return ans;
}