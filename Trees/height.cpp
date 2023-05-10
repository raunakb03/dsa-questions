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

int f(Node *node)
{
    if (node == NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return 1;
    int leftHeight = 0, rightHeight = 0;
    if (node->left)
    {
        leftHeight = f(node->left);
    }
    if (node->right)
    {
        rightHeight = f(node->right);
    }
    return 1 + max(leftHeight, rightHeight);
}
int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return f(node);
}