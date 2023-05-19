#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *arb;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->arb = NULL;
    }
};
Node *copyList(Node *head)
{
    Node *temp = head;
    // step 1
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
    // step 2
    Node *itr = head;
    while (itr != NULL)
    {
        if (itr->arb != NULL)
            itr->next->arb = itr->arb->next;
        itr = itr->next->next;
    }
    // step 3
    Node *dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node *fast;
    while (itr != NULL)
    {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = itr->next;
    }
    return dummy->next;
}