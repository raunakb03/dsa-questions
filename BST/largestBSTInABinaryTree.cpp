#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

class NodeValue
{
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeValue f(Node *root)
{

    // return [inf, -inf] so that its parent would be a valid bst in all cases
    if (root == NULL)
    {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // get values from left and right subtree of the current tree
    auto left = f(root->left);
    auto right = f(root->right);

    // current node is greater than max in left and smaller than min in right then is BST
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
    }

    // return [-inf, inf] so that its parent wont be a valid bst
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}
int largestBst(Node *root)
{
    return f(root).maxSize;
}