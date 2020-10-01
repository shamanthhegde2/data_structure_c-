#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
void insertion(node *&head,int data)
{
    if(head==NULL)
    {
        head=new node(data);
        head->next=head;
        return;
    }
    node *n=new node(data);
    node *temp{head};
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deletion(node *&head)
{
    if(head==NULL)
        return;
    node *temp{head};
    node *p;
    while(temp->next!=head)
    {
        p=temp;
        temp=temp->next;
    }
    p->next=temp->next;
    delete temp;
}
void print(node *head)
{
    if(head==NULL)
        return;
    node *temp{head};
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
    cout<<endl;
}

void insert_at_pos(node *&head,int data,int pos)
{
    if(head==NULL)
    {
        insertion(head,data);
        return;
    }
    pos=pos-2;
    node *temp{head};
    while(pos--  && temp->next!=head)
    {
        temp=temp->next;
    }
    if(pos==1)
        temp=temp->next;
    if(temp==NULL)
    {
        return;
    }
    node *n=new node(data);
    n->next=temp->next;
    temp->next=n;
}

void deletion_at_pos(node *&head,int pos)
{
    if(head==NULL)
        return;
    node *temp{head};
    node *p;
    while(pos-- && temp->next!=head)
    {
        p=temp;
        temp=temp->next;
    }
    if(pos==1 && temp->next==head)
    {
        p=temp;
        temp=temp->next;
    }
    p->next=head;
    delete temp;
}
int main()
{
    node *head=NULL;
    insertion(head,1);
    insertion(head,3);
    insert_at_pos(head,2,2);
    print(head);
    deletion(head);
    print(head);
    deletion_at_pos(head,2);
    print(head);
}