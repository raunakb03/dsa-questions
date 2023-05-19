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

// method 1
// merge sort of a linked list
ListNode *merge(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL && head2 == NULL)
        return head1;

    ListNode *temp1 = head1;
    ListNode *temp2 = head2;
    ListNode *ans = new ListNode(-1);
    ListNode *ftemp = ans;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val <= temp2->val)
        {
            ListNode *insertListNode = new ListNode(temp1->val);
            ans->next = insertListNode;
            temp1 = temp1->next;
        }
        else
        {
            ListNode *insertListNode = new ListNode(temp2->val);
            ans->next = insertListNode;
            temp2 = temp2->next;
        }
        ans = ans->next;
    }

    while (temp1 != NULL)
    {
        ListNode *insertListNode = new ListNode(temp1->val);
        ans->next = insertListNode;
        ans = ans->next;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        ListNode *insertListNode = new ListNode(temp2->val);
        ans->next = insertListNode;
        ans = ans->next;
        temp2 = temp2->next;
    }
    return ftemp->next;
}
ListNode *middle(ListNode *head)
{
    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *mergeSort(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *mid = middle(head);
    ListNode *head2 = mid->next;
    mid->next = NULL;

    ListNode *ans = merge(mergeSort(head), mergeSort(head2));
    return ans;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *mergedHead = new ListNode(-1);
    ListNode *temp = mergedHead;
    for (auto c : lists)
    {
        temp->next = c;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    ListNode *ans = mergeSort(mergedHead->next);
    return ans;
}

// method 2
ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }
    if (l1->val <= l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    ListNode *temp = lists[0];
    for (int i = 1; i < lists.size(); i++)
    {
        temp = merge(temp, lists[i]);
    }
    return temp;
}