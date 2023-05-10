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

void preorderIterative(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        Node *curr = stack.top();
        stack.pop();

        cout << curr->data << " ";
        if (curr->right)
            stack.push(curr->right);
        if (curr->left)
            stack.push(curr->left);
    }
}