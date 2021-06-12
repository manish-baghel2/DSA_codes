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

node* reversek(node* &head, int k)
{
    node* prev = NULL;
    node* curr = head;
    node* next;
    int count=0;  
    while(curr != NULL && count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next !=NULL ){
        head->next = reversek(next, k);
    }
    return prev;
}

// detection of cycle (** floyds algorithm or hare and tortoise algorithm)
bool detection (node* &head)
{
    node* temp = head;
    node* t = head;
    node* h = head;
    while (temp!=NULL)
    {
        t =  head->next;
        h = head->next->next;
        if(t->data == h->data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
   node* head = NULL;
   insertatend(head, 1);
   insertatend(head, 2);
   insertatend(head, 3);
   insertatend(head, 4);
   insertatend(head, 5);
   insertatend(head, 6);
   display(head);
//    int k=2;
//    node* newhead = reversek(head, k);
//    display(newhead);
   cout<<detection(head)<<endl;
   return 0;
}