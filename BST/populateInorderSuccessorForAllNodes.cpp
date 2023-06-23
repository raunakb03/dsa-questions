#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *left;
    Node *right;
};

Node *temp = NULL;
void populateNext(Node *p)
{
    if (p)
    {
        populateNext(p->right);
        p->next = temp;
        temp = p;
        populateNext(p->left);
    }
}