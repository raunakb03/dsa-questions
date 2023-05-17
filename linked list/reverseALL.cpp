#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int d)
    {
        this->val = d;
        this->next = NULL;
    }
};

ListNode *f(ListNode *node)
{
    if (node == NULL || node->next == NULL)
        return node;
    ListNode *rest = f(node->next);
    node->next->next = node;
    node->next = NULL;
    return rest;
}
ListNode *reverseList(ListNode *head)
{
    // recursive method
    if (head == NULL || head->next == NULL)
        return head;
    return f(head);

    // iterative solution
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *temp;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}