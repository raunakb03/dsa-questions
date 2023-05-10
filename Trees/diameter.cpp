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

pair<int, int> f(Node *root)
{
    if (root == NULL)
        return {0, 0};

    pair<int, int> left = f(root->left);
    pair<int, int> right = f(root->right);

    pair<int, int> ans;
    ans.first = max(left.first, max(right.first, left.second + right.second + 1));
    ans.second = 1 + max(left.second, right.second);

    return ans;
}
int diameter(Node *root)
{
    pair<int, int> ans = f(root);
    return ans.first;
}