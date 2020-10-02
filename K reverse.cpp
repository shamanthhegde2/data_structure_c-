struct node *reverse (struct node *head, int k)
{
    if(head==NULL || head->next==NULL)
    return head;
    int count=k;
    struct node *p{NULL};
    struct node *c{head};
    struct node *n;
    while(c!=NULL && count--)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head->next=reverse(n,k);
    return p;
}