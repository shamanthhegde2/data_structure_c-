ListNode *reverse(ListNode *head)
    {
        ListNode *p{NULL};
        ListNode *c{head};
        ListNode *n;
        while(c!=NULL)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode *fast{head};
        ListNode *slow{head};
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=head;
        slow=reverse(slow);
        while(slow!=NULL)
        {
            if(fast->val!=slow->val)
                return false;
            fast=fast->next;
            slow=slow->next;
                
        }
        return true;
    }