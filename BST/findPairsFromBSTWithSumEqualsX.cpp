#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

void findElements(Node *root, unordered_map<int, int> &mp)
{
    if (root == NULL)
        return;
    mp[root->data]++;
    findElements(root->left, mp);
    findElements(root->right, mp);
}
int f(Node *root, int x, unordered_map<int, int> &mp)
{
    if (root == NULL)
        return 0;
    int diff = x - root->data;
    int ans = 0;
    if (mp.count(diff))
        ans++;

    return ans + f(root->left, x, mp) + f(root->right, x, mp);
}
int countPairs(Node *root1, Node *root2, int x)
{
    unordered_map<int, int> mp1;
    findElements(root1, mp1);
    return f(root2, x, mp1);
}