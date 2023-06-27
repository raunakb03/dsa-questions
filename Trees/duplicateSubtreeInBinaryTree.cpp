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

map<string, int> mp;
string dfs(Node *root, int &ans)
{
    if (root == NULL)
        return "null";
    string s = ',' + to_string(root->data);
    string left = dfs(root->left, ans);
    string right = dfs(root->right, ans);
    s += left + right;
    if (!(root->left == NULL && root->right == NULL) && mp[s] > 0)
    {
        ans = 1;
    }
    mp[s]++;
    return s;
}
int dupSub(Node *root)
{
    int ans = 0;
    dfs(root, ans);
    return ans;
}