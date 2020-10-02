 ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *odd{head};
        ListNode *even{head->next};
        ListNode *even_head{head->next};
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=even_head;
        return head;
    }