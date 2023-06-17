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
ListNode *removeZeroSumSublists(ListNode *head)
{
    if (head == NULL)
        return head;
    unordered_map<int, ListNode *> m;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    m[0] = dummy;
    int prefix_sum = 0;
    while (head != NULL)
    {
        prefix_sum += head->val;
        if (m.find(prefix_sum) != m.end())
        {
            ListNode *start = m[prefix_sum];
            int sum = prefix_sum;
            while (start != NULL && start != head)
            {
                start = start->next;
                sum += start->val;
                if (start != head)
                {
                    m.erase(sum);
                }
            }
            m[prefix_sum]->next = head->next;
        }
        else
        {
            m[prefix_sum] = head;
        }
        head = head->next;
    }
    return dummy->next;
}