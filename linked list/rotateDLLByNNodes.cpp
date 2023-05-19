#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int d)
    {
        this->val = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

ListNode *rotateByKNodes(ListNode *head, int k)
{
    if (!k)
        return head;

    // fidn the tail of the linked list
    ListNode *tail = head;
    while (tail != NULL)
        tail = tail->next;

    // making the list circular
    tail->next = head;
    head->prev = tail;

    while (k--)
    {
        tail = tail->next;
        head = head->next;
    }
    tail->next = NULL;
    head->prev = NULL;
    return head;
    // here we just change the position of the head and return it
}