ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void reorderList(ListNode *head)
{

    // find the mid of the list
    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the second lalf and get the tow list
    ListNode *second = reverse(slow->next);
    slow->next = NULL;
    ListNode *first = head;

    // merge the two list
    while (second && first)
    {
        ListNode *temp = first->next;
        first->next = second;
        ListNode *temp2 = second->next;
        second->next = temp;
        first = temp;
        second = temp2;
    }
}