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

vector<int> reverseLevelOrder(Node *root)
{
    if (root == NULL)
        return {};
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> ans;
    vector<int> temp;
    q.push(NULL);
    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            ans.push_back(temp);
            temp.clear();
            q.pop();
            if (!q.empty())
                q.push(NULL);
            if (q.empty())
                break;
        }
        auto node = q.front();
        q.pop();
        temp.push_back(node->data);
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    vector<int> fans;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        for (auto c : ans[i])
            fans.push_back(c);
    }
    return fans;
}