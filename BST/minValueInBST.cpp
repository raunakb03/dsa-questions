#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
int minValue(Node *root)
{

    if (root == NULL)
        return -1;
    int mini = 1e9;

    Node *temp = root;
    while (temp != NULL)
    {
        mini = min(mini, temp->data);
        temp = temp->left;
    }

    if (mini == 1e9)
        return -1;

    return mini;
}
