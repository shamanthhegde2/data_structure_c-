#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
void insert_at_head(node *&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        return;
    }
    node *n=new node(data);
    n->next=head;
    head->prev=n;
    head=n;
}
void print(node *head)
{
    if(head==NULL)
        return;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insert_at_tail(node *&head,int data)
{
    node *n=new node(data);
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void insert_at_pos(node *&head,int data,int pos)
{
    if(head==NULL)
    {
        insert_at_head(head,data);
        return;
    }
    pos=pos-2;
    node *temp{head};
    while(pos--  && temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    node *n=new node(data);
    n->prev=temp;
    n->next=temp->next;
    temp->next=n;
    if(n->next!=NULL)
    n->next->prev=n;
}
void delete_at_head(node *&head)
{
    if(head==NULL)
    return;
    node *temp{head};
    head=head->next;
    delete temp;

}
void delete_at_pos(node *&head,int pos)
{
    if(head==NULL)
    return;
    pos=pos-1;
    node *temp{head};
    node *p;
    while(pos-- && temp!=NULL)
    {
        p=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    return;
    p->next=temp->next;
    if(temp->next!=NULL)
    {
        temp->next->prev=p;
    }
    delete temp;
}
void delete_at_end(node *&head)
{
    if(head==NULL)
    return;
    node *temp{head};
    node *p;
    while(temp->next!=NULL)
    {
        p=temp;
        temp=temp->next;
    }
    p->next=NULL;
    delete temp;
}
bool search_itr(node *head,int search)
{
    if(head==NULL)
    return false;
    while(head!=NULL)
    {
        if(search==head->data)
        return true;
        head=head->next;
    }
    return false;
}
bool search_Rec(node *head,int search)
{
    if(head==NULL)
    return false;
    if(head->data==search)
    return true;
    return search_Rec(head->next,search);
}
void reverse_DLL(node *&head)
{
    if(head==NULL)
    return;
    node *p{NULL};
    node *c{head};
    node *n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        c->prev=n;
        p=c;
        c=n;
    }
    head=p;
}
int main()
{
    node *head=NULL;
    insert_at_head(head,1);
    insert_at_pos(head,2,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    print(head);
    delete_at_head(head);
    delete_at_pos(head,2);
    delete_at_end(head);
    print(head);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,7);
    print(head);
    if(search_itr(head,5))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    if(search_Rec(head,10))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
    print(head);
    reverse_DLL(head);
    print(head);
}