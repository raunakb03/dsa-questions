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

unordered_map<Node *, int> umap;
int maxSum(Node *root)
{
    if (!root)
        return 0;
    if (umap[root])
        return umap[root];

    int inc = root->data;
    if (root->left)
    {
        inc += maxSum(root->left->left) + maxSum(root->left->right);
    }
    if (root->right)
    {
        inc += maxSum(root->right->left) + maxSum(root->right->right);
    }
    int ex = maxSum(root->left) + maxSum(root->right);
    umap[root] = max(inc, ex);
    return max(inc, ex);
}