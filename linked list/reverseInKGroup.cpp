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
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    for (int i = 0; i < k; i++)
    {
        if (temp == NULL)
            return head;
        temp = temp->next;
    }

    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *nxt = NULL;
    for (int i = 0; i < k; i++)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head->next = reverseKGroup(curr, k);
    return prev;
}