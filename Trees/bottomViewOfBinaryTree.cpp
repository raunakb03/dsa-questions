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

vector<int> bottomView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto node = q.front().first;
        auto line = q.front().second;
        q.pop();
        mp[line] = node->data;
        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }
    vector<int> ans;
    for (auto c : mp)
    {
        ans.push_back(c.second);
    }
    return ans;
}