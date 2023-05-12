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

bool check(Node *root)
{
    if (root == NULL)
        return 1;
    queue<Node *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);

            if (temp->left == NULL && temp->right == NULL)
            {
                flag = 1;
            }
        }
        if (flag && !q.empty())
            return 0;
    }
    return true;
}