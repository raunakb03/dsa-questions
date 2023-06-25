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
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return head;
    int totalNodes = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        totalNodes++;
        temp = temp->next;
    }
    // linking last nodes to the first node
    ListNode *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head;
    int nodeFromBack = k % totalNodes; // this node is the new head
    int nodesToTravel = totalNodes - nodeFromBack;
    ListNode *prev = new ListNode(-1);
    ListNode *curr = head;
    prev->next = curr;
    while (nodesToTravel--)
    {
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = NULL;
    return curr;
}