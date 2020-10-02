void insertAtHead(node *&head,int data)
{
    node *n=new node(data);
    n->next=head;
    head=n;
}
void insertAtMiddle(node *&head,int pos,int data)
{
    node *temp=head;
    pos=pos-2;
    while(temp!=NULL && pos--)
    {
        temp=temp->next;
    }
    node *n=new node(data);
    n->next=temp->next;
    temp->next=n;
}
void insertAtTail(node *&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new node(data);
}
void deleteAtHead(node *&head)
{
    if(head==NULL)
    {
        cout<<"Empty to delete"<<endl;
        return;
    }
    node *temp=head;
    head=head->next;
    delete temp;
}
void deleteAtMiddle(node *&head,int pos)
{
    pos=pos-1;
    node *temp=head;
    node *prev;
    while(temp!=NULL && pos--)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete  temp;
}
void deleteAtTail(node *&head)
{
    node *temp=head;
    node *prev;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;

}
bool searchLL(node *head,int data)
{
    while(head!=NULL)
    {
        if(data==head->data)
        return true;
        head=head->next;
    }
    return false;
}
bool searchRR(node *head,int data)
{
    if(head==NULL)
    return false;
    if(head->data==data)
    return true;
    return searchRR(head->next,data);
}
void reverse(node *&head)
{
    node *p=NULL;
    node *c=head;
    node *n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}
void print(node *head)
{
    if(head==NULL)
    {
        cout<<"empty"<<endl;
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int midPoint(node *head)
{
    node *fast=head->next;
    node *slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
node *Kth_node_from_last(node *head,int k)
{
    if(head==NULL)
    return;
    node *fast{head};
    node *slow{head};
    while(k--)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}