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
        return {1, 0};
    pair<int, int> left = f(root->left);
    pair<int, int> right = f(root->right);

    pair<int, int> ans;

    if (left.first == 0 || right.first == 0 || abs(left.second - right.second) > 1)
    {
        ans.first = 0;
    }
    else
    {
        ans.first = 1;
    }
    ans.second = 1 + max(left.second, right.second);

    return ans;
}
bool isBalanced(Node *root)
{
    return f(root).first;
}