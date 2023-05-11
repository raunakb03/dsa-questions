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
vector<int> zigZagTraversal(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
        return {};
    bool ltr = 1;
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        int ind;
        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();
            temp.push_back(node->data);
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        if (!ltr)
        {
            reverse(temp.begin(), temp.end());
        }
        ltr = !ltr;
        for (auto c : temp)
        {
            ans.push_back(c);
        }
    }
    return ans;
}