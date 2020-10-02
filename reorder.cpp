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
    void merge(ListNode *headA,ListNode *headB)
    {
        while(headA!=NULL)
        {
            ListNode *a=headA->next;
            ListNode *b=headB->next;
            headA->next=headB;
            if(a==NULL)
                break;
            headB->next=a;
            headA=a;
            headB=b;
        }
    }
    void reorderList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return;
        ListNode *fast{head};
        ListNode *slow{head}; 
        ListNode *prev;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=NULL;
        ListNode *headA=head;
        ListNode *headB=reverse(slow);
        merge(headA,headB);
    }
