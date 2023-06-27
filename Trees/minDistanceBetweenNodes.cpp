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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return root;
    if (root->key == n1 || root->key == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;
    if (left == NULL && right == NULL)
        return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);

    return LCA(root->right, n1, n2);
}

void f(Node *lca, int x, int l, int &ans)
{
    if (lca == NULL)
        return;
    if (lca->data == x)
        ans = l;
    f(lca->left, x, l + 1, ans);
    f(lca->right, x, l + 1, ans);
}
int findDist(Node *root, int a, int b)
{
    Node *lca = LCA(root, a, b);
    int l1 = -1, l2 = -1;
    f(lca, a, 0, l1);
    f(lca, b, 0, l2);

    return l1 + l2;
}