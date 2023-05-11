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

void f(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    f(root->right, ans, level + 1);
    f(root->left, ans, level + 1);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    f(root, ans, 0);
    return ans;
}