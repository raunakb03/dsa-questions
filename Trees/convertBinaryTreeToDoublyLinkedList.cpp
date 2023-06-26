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

void f(Node *root, Node *&prev, Node *&dummy)
{
    if (root == NULL)
        return;
    f(root->left, prev, dummy);
    if (prev == NULL)
    {
        root->left = prev;
        prev = root;
        dummy = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
        prev = root;
    }
    f(root->right, prev, dummy);
}
Node *bToDLL(Node *root)
{
    Node *dummy = new Node(-1);
    Node *prev = NULL;
    dummy->right = prev;
    f(root, prev, dummy);
    return dummy;
}