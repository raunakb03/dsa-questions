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
    auto left = f(root->left);
    auto right = f(root->right);

    pair<int, int> ans;
    if (left.second > right.second)
    {
        ans.first = left.first + root->data;
    }
    else if (left.second < right.second)
    {
        ans.first = right.first + root->data;
    }
    else
        ans.first = max(right.first, left.first) + root->data;

    ans.second = max(left.second, right.second) + 1;

    return ans;
}
int sumOfLongRootToLeafPath(Node *root)
{
    return f(root).first;
}