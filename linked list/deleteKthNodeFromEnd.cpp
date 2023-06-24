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

// two pass method
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // find the length of the whole list
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    // the node which we want to delete
    int nodeToDelete = len - n;

    // if to delete start node;
    if (nodeToDelete == 0)
        return head->next;

    ListNode *curr = head;
    ListNode *prev = new ListNode(-1);
    prev->next = curr;
    while (nodeToDelete--)
    {
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;

    return head;
}

// one pass method
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (n--)
        fast = fast->next;
    if (!fast)
        return head->next;
    while (fast->next)
        fast = fast->next, slow = slow->next;

    slow->next = slow->next->next;

    return head;
}