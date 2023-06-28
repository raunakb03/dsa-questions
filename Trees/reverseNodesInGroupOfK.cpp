#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d)
    {
        this->val = d;
        left = NULL;
        right = NULL;
    }
};

// recursion approach
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    for (int i = 0; i < k; i++)
    {
        if (temp == NULL)
            return head;
        temp = temp->next;
    }

    // reverse the first k nodes;
    int cnt = 0;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // recursion
    if (curr != NULL)
        head->next = reverseKGroup(curr, k);

    return prev;
}

// iterative approach
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    while (cur->next != NULL)
    {
        cur = cur->next;
        count++;
    }
    while (count >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }
    return dummy->next;
}