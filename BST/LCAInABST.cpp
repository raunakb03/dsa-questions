#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *LCA(Node *root, int n1, int n2)
{
    // the first node in which we split is the ans
    Node *temp = root;
    Node *ans;
    while (temp->data != n1 || temp->data != n2)
    {
        if (temp->data == n1 || temp->data == n2)
            return temp;

        if ((temp->data < n1 && temp->data < n2))
        {
            temp = temp->right;
        }
        else if ((temp->data > n1 && temp->data > n2))
        {
            temp = temp->left;
        }
        else
            return temp;
    }
}