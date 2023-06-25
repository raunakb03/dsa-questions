#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

void allNodes(Node *root, unordered_map<int, int> &mp)
{
    if (root == NULL)
        return;
    mp[root->data] = 1;
    allNodes(root->left, mp);
    allNodes(root->right, mp);
}

bool check(Node *root, unordered_map<int, int> &mp)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
    {
        if (mp.find(root->data - 1) != mp.end() && mp.find(root->data + 1) != mp.end())
            return true;
    }
    return check(root->left, mp) + check(root->right, mp);
}

bool isDeadEnd(Node *root)
{
    unordered_map<int, int> mp;
    // if tree contains 1 then also return true
    mp[0] = 1;
    allNodes(root, mp);
    return check(root, mp);
}