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
bool hasCycle(ListNode *head) {
        ListNode* fast= head;
        ListNode* slow= head;
        while(fast!=NULL && fast->next!=NULL){
            fast= fast->next->next;
            slow= slow->next;
            if(fast==slow) return true;

        }
        return false;
    }