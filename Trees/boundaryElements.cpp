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

bool isLeafNode(Node *node)
{
    if (node == NULL)
        return false;
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

void leftNodes(Node *root, vector<int> &res)
{
    auto curr = root->left;
    while (curr)
    {
        if (!isLeafNode(curr))
            res.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void leafNodes(Node *root, vector<int> &res)
{
    if (isLeafNode(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        leafNodes(root->left, res);
    if (root->right)
        leafNodes(root->right, res);
}

void rightNodes(Node *root, vector<int> &res)
{
    auto curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeafNode(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    for (auto c : temp)
        res.push_back(c);
}

vector<int> boundary(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeafNode(root))
        res.push_back(root->data);
    leftNodes(root, res);
    leafNodes(root, res);
    rightNodes(root, res);
    return res;
}