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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *node = new ListNode(0);
    ListNode *temp = node;
    int sum = 0, carry = 0;
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    while (temp1 != NULL && temp2 != NULL)
    {
        sum = (temp1->val + temp2->val + carry) % 10;
        carry = (temp1->val + temp2->val + carry) / 10;
        ListNode *newNode = new ListNode(sum);
        node->next = newNode;
        node = newNode;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            sum = (temp1->val + carry) % 10;
            carry = (temp1->val + carry) / 10;
            ListNode *newNode = new ListNode(sum);
            node->next = newNode;
            node = newNode;
            temp1 = temp1->next;
        }
    }
    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            sum = (temp2->val + carry) % 10;
            carry = (temp2->val + carry) / 10;
            ListNode *newNode = new ListNode(sum);
            node->next = newNode;
            node = newNode;
            temp2 = temp2->next;
        }
    }
    if (carry != 0)
    {
        ListNode *newNode = new ListNode(carry);
        node->next = newNode;
        newNode->next = NULL;
    }
    return temp->next;
}