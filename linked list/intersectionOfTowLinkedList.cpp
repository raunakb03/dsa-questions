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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp = headA;
    while (temp != NULL)
    {
        temp->val = -temp->val;
        temp = temp->next;
    }
    temp = headB;
    while (temp != NULL)
    {
        if (temp->val < 0)
        {
            ListNode *temp2 = headA;
            while (temp2 != NULL)
            {
                if (temp2->val < 0)
                    temp2->val = -temp2->val;
                temp2 = temp2->next;
            }
            return temp;
        }
        temp = temp->next;
    }
    ListNode *temp2 = headA;
    while (temp2 != NULL)
    {
        if (temp2->val < 0)
            temp2->val = -temp2->val;
        temp2 = temp2->next;
    }
    return NULL;
}