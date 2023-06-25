#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node *curr, Node *&prev)
{
    if (curr == NULL)
        return;

    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}

Node *flatten(Node *parent)
{
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    inorder(parent, prev);

    prev->left = NULL;
    prev->right = NULL;
    Node *rest = dummy->right;

    return rest;
}
