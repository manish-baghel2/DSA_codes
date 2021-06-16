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

// display the whole linked list
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

// detection of cycle (**floyds algorithm or hare and tortoise algorithm**)
bool detection (node* &head)
{
    node* temp = head;
    node* t = head;
    node* h = head;
    while (temp!=NULL)
    {
        t =  t->next;
        h = h->next->next;
        if(t->data == h->data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// making a loop in linked list for testing algorithm of deleting the loop
void makeloop(node* &head, int val1)
{
    node* start;
    node* temp = head;
    while(temp->next !=NULL)
    {
        if(temp->data == val1)
        {
            start = temp;
        }
        temp=temp->next;
    }
    temp->next= start;

}

// removing a loop from a linked list
void removeloop(node* &head)
{
    node* slow = head;
    node* fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast);
    fast = head;
    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
// append last k nodes  (** improved **)
// void appendknodes(node* &head, int k)
// {
//     node* newhead;
//     node* newtail;
//     node* tail = head;
//     int count=counting(head);
//     int l=1;
//     k=k%count;
//     while(tail->next != NULL)
//     {
//         if(l == count-k)
//         {
//             newtail = tail;
//         }
//         if(l == count-k +1)
//         {
//             newhead = tail;
//         }
//         tail = tail->next;
//         l++;
//     }
//     tail->next = head;
//     newtail->next = NULL;
//     head = newhead;
// }

// counting the number of elements in a linked list
int counting(node* head)
{
    int l=0;
    while(head != NULL)
    {
        head = head->next;
        l++;
    }
    return l;
}

// intersecting two linked lists
void intersectat(node* &head, node* &head2, int k)
{
    node* temp = head;
    node* temp2 = head2;
    int length = counting(head);
    length = length-k;
    for(int i=1;i<=length;i++)
    {
        temp = temp->next;
    }
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

// find the intersection between the two lists
void intersectionpoint(node* &head, node* &head2, int k)
{
    int l1 = counting(head);
    int l2 = counting(head2);
    node* ptr1;
    node* ptr2;
    int d;
    if(l1>l2)
    {
        ptr1 = head;
        ptr2 = head2;
        d= l1-l2;
    }else
    {
        ptr1 = head2;
        ptr2 = head;
        d = l2-l1;
    }
    for(int i=0;i<d; i++)
    {
        ptr1 = ptr1->next;
    }
    
}

// merging two sorted lists(using while loops)
node* merge1(node* &head, node* &head2)
{
    node* ptr1 = head;
    node* ptr2 = head2;
    node* dummynode=new node(-1);
    node* ptr3 = dummynode;
    while( ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr2->data<ptr1->data)
        {
            ptr3->next = ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }else if(ptr1->data<ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
    }
    while(ptr1!=NULL)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
            ptr3=ptr3->next;
        }while(ptr2!=NULL)
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
            ptr3=ptr3->next;
        }
    return dummynode->next;
}

// merging two sorted lists by recursion
node* mergerecursion(node* &head, node* &head2)
{
    if(head == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head;
    }
    node* result;
    if(head->data<head2->data)
    {
        result=head;
        result->next = mergerecursion(head->next, head2);
    }else
    {
        result = head2;
        result->next = mergerecursion(head, head2->next);
    }
    return result;
}

int main()
{
   node* head = NULL;
   node* head2 = NULL;
   int ar1[] ={1, 4, 5, 7};
   int ar2[] = {2, 3, 6};
   for(int i:ar1)
   {
       insertatend(head, i);
   }
   for(int i: ar2)
   {
       insertatend(head2, i);
   }
//    display(head);
//    display(head2);
   node* newhead = mergerecursion(head, head2);
   display(newhead);
//    insertatend(head, 1);
//    insertatend(head, 2);
//    insertatend(head, 3);
//    insertatend(head, 4);
//    insertatend(head, 5);
//    insertatend(head, 6);
//    insertatend(head, 7);
//    insertatend(head, 8);
//    insertatend(head, 9);
//    insertatend(head, 10);
//    insertatend(head, 11);
//    insertatend(head2, 12);
//    insertatend(head2, 13);
//    intersectat(head, head2, 3);
//    display(head2);
//    intersectionpoint(head, head2, 3);
//    makeloop(head, 5);
//    display(head);
//    int k=2;
//    node* newhead = reversek(head, k);
//    display(newhead);
//    cout<<detection(head)<<endl;
//    removeloop(head);
//    display(head);
//    cout<<detection(head);
//    appendknodes(head, 3);
//    display(head);
   return 0;
}