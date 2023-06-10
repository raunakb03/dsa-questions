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
    }
};

bool isHeap(struct Node *tree)
{
    queue<Node *> q;
    q.push(tree);
    bool ans = false;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            if (ans || temp->left->data > temp->data)
            {
                return false;
            }
            q.push(temp->left);
        }
        else
        {
            ans = true;
        }
        if (temp->right)
        {
            if (ans || temp->right->data > temp->data)
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            ans = true;
        }
    }
    return true;
}