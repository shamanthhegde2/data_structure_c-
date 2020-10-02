ListNode *mid_point(ListNode *head)
    {
        ListNode *slow{head};
        ListNode *fast{head->next};
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *mergeSort(ListNode *a,ListNode *b)
    {
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        ListNode *c;
        if(a->val<=b->val)
        {
            c=a;
            c->next=mergeSort(a->next,b);
        }
        else
        {
            c=b;
            c->next=mergeSort(a,b->next);
        }
        return c;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *mid=mid_point(head);
        ListNode *headA{head};
        ListNode *headB;
        headB=mid->next;
        mid->next=NULL;
        headA=sortList(headA);
        headB=sortList(headB);
        ListNode *c=mergeSort(headA,headB);
        return c;
    }