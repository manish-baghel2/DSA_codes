#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertatend(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
}

node* mergelist(node* &head, node* &head2)
{
    node* n1 = head;
    node* n2 = head2;
    node* dummy = new node(-1);
    node* temp=dummy;
    while(n1 != NULL && n2 != NULL)
    {
        if(n2->data > n1->data)
        {
            temp->next = n1;
            n1= n1->next;
            temp=temp->next;
        }else
        {
            temp->next = n2;
            n2 = n2->next;
            temp=temp->next;
        }
    }
    while(n1!=NULL)
    {
        temp->next = n1;
        n1= n1->next;
        temp=temp->next;
    }
    while(n2!=NULL)
    {
        temp->next = n2;
        n2=n2->next;
        temp=temp->next;
    }
    return dummy->next;
}

// printing the linked list
void print(node* head)
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int main()
{
    node* head=NULL;
    node* head2 = NULL;
    int n, val;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        insertatend(head, val);
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        insertatend(head2, val);
    }
    node* newhead = mergelist(head, head2);
    print(newhead);
}