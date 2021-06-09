#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* next=NULL;
    
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertatend(node* &head, int val)
{
    node* temp = head;
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void insertatstart(node* &head, int val)
{
    node* temp = head;
    node* n = new node(val);
    n->next = temp;
    head = n;
}

node* reverseiterate(node* &head)
{
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL)
    {
        next=curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node* reverserecursion(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node* newhead = reverserecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
    
}

int main()
{
   node* head = NULL;
   insertatstart(head, 0);
   insertatend(head, 1);
   insertatend(head, 2);
   insertatend(head, 3);
   insertatend(head, 4);
   insertatend(head, 5);
   insertatend(head, 6);
   display(head);
   node* newhead = reverserecursion(head);
   display(newhead);
}