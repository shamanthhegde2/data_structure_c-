ListNode *detectCycle(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *fast{head};
        ListNode *slow{head};
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                fast=head;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
            
        }
        return NULL;
    }