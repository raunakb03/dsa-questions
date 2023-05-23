#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

pair<int, int> findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // predecessor is the max element in the left substree of the node with the val
    // successor is the min element in thr right substree of the node with the val

    Node *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            // as this shows temp right now is on the right side of the tree
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            // this shows temp right now is on the left side of the tree
            pred = temp->data;
            temp = temp->right;
        }
    }

    // finding the pred
    Node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // finding the succ
    Node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}