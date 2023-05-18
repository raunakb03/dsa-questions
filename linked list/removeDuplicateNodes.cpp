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
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    if (head == NULL || head->next == NULL)
        return head;
    while (temp != NULL && temp->next != NULL)
    {
        int curr = temp->val;
        int next = temp->next->val;
        if (curr == next)
            temp->next = temp->next->next;
        curr = temp->val;
        if (temp->next != NULL)
            next = temp->next->val;
        else
            next = -101;
        if (curr != next)
            temp = temp->next;
    }
    return head;
}