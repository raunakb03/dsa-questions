class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return NULL;
        Node *curr = head;
        while (curr)
        {
            Node *head1 = curr;
            if (curr->child != NULL)
            {
                Node *child = flatten(curr->child);
                curr->child = NULL;
                // merge the next of this and the child pointer
                Node *next = curr->next;
                Node *head2 = child;
                while (head2 != NULL)
                {
                    head1->next = head2;
                    head2->prev = head1;
                    head2 = head2->next;
                    head1 = head1->next;
                }
                head1->next = next;
                if (next)
                    next->prev = head1;
            }
            curr = head1->next;
        }
        return head;
    }
};