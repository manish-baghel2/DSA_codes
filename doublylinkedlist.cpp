// unlike our linear linked list doubly linked list has two pointer positions one for next and other for previous pointer details this helps in moving 
// in both forward and backward direction and helps in commute 
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    
    node(int val)
    {
        data = val;
        next=NULL;
        prev=NULL;
    }
};

// insert at start function
void insertatstart(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    if(head != NULL)
    {
        head->prev = n;
    }
    head = n;
}
// function to add at the end of list
void insertatend(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;
    if(head == NULL)
    {
        head = n;
        return;
    }
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

// display the linked list
void display(node* head)
{
    while(head->next != NULL)
    {
        cout<<head->data<<"<->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

// deletion of head
void headdelete(node* &head)
{
    node* todelete = head;
    head->next->prev =NULL;
    head = head->next;
    delete todelete;
}

// deletion of a given position
void deletion(node* &head, int pos)
{
    if(pos == 1)
    {
        headdelete(head);
        return;
    }
    node* temp = head;
    int count=1;
    while(temp->next != NULL && count != pos)
    {
        count++;
        temp = temp->next;   
    }
    temp->next->prev = temp->prev;
    if(temp->next!=NULL)
    {
        temp->prev->next = temp->next;
    }
}

int main(){
    node* head = NULL;
    insertatend(head, 1);
    insertatend(head, 2);
    insertatend(head, 3);
    insertatend(head, 4);
    insertatend(head, 5);
    insertatend(head, 6);
    insertatstart(head, 0);
    display(head);
    deletion(head, 2);
    display(head);
}
