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

// recursive approach
void f(Node *root, int line, map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;
    mp[line].push_back(root->data);
    f(root->left, line + 1, mp);
    f(root->right, line, mp);
}
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int, vector<int>> mp;
    f(root, 0, mp);
    for (auto c : mp)
    {
        for (auto it : c.second)
            ans.push_back(it);
    }
    return ans;
}

// iterative approach
vector<int> diagonal(Node *root)
{
    Node *node = root;
    queue<Node *> left;
    vector<int> ans;
    while (node)
    {
        ans.push_back(node->data);
        if (node->left)
            left.push(node->left);

        if (node->right)
            node = node->right;
        else
        {
            if (!left.empty())
            {
                node = left.front();
                left.pop();
            }
            else
                node = NULL;
        }
    }
    return ans;
}