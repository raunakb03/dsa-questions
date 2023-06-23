#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
int kthLargest(Node *root, int &k)
{
    if (root == NULL)
        return -1;
    int right = kthLargest(root->right, k);
    if (right != -1)
        return right;
    k--;
    if (k == 0)
        return root->data;
    int left = kthLargest(root->left, k);
    if (left != -1)
        return left;

    return -1;
}