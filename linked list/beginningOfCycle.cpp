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
ListNode *hasCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;

        if (slow == fast)
            return slow;
    }
    return NULL;
}
ListNode *detectCycle(ListNode *head)
{
    ListNode *intersection = hasCycle(head);
    if (intersection == NULL)
        return NULL;
    ListNode *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}