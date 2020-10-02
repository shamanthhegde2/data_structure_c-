int length(ListNode *head)
    {
        if(head==NULL)
            return 0;
        int count=0;
        while(head!=NULL)
        {
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(headA==NULL || headB==NULL)
            return NULL;
        int count1=length(headA);
        int count2=length(headB);
        if(count1>=count2)
        {
            int diff=count1-count2;
            while(diff--)
                headA=headA->next;
        }
        else
        {
            int diff=count2-count1;
            while(diff--)
                headB=headB->next;
        }
        while(headA!=NULL)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }