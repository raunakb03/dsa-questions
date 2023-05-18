#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
        return head1;

    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *ans = new Node(-1);
    Node *ftemp = ans;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            Node *insertNode = new Node(temp1->data);
            ans->next = insertNode;
            temp1 = temp1->next;
        }
        else
        {
            Node *insertNode = new Node(temp2->data);
            ans->next = insertNode;
            temp2 = temp2->next;
        }
        ans = ans->next;
    }

    while (temp1 != NULL)
    {
        Node *insertNode = new Node(temp1->data);
        ans->next = insertNode;
        ans = ans->next;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        Node *insertNode = new Node(temp2->data);
        ans->next = insertNode;
        ans = ans->next;
        temp2 = temp2->next;
    }
    return ftemp->next;
}
Node *middle(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *mid = middle(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    Node *ans = merge(mergeSort(head), mergeSort(head2));
    return ans;
}