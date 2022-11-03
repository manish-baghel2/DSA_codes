#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* next; 
    public:
        Node(int data){
            val = data;
            next = NULL;
        }
        ~Node(){
            int val = this->val;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
                cout<<"node with value "<<val<<" was deleted"<<endl;
            }
        }
};

Node* insertAthead(Node* head, int n){
    Node* temp = new Node(n);
    temp->next = head;
    head = temp;
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

// insert at tail;
Node* insertAtTail(Node* head, int n){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* nextNode = new Node(n);
    temp->next=nextNode;
    return head;
}

void deletion(Node* &head, int n){
    if(head->val == n){
    head = head->next;
    return;
    } 
        
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->val == n){
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
}

void deletenode(Node* head, int p){
    if(p==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* prev = NULL;
        Node* curr = head;
        int c = 1;
        while(c < p){
            prev = curr;
            curr = curr->next;
            c++;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// insert in middle : my attempt
void insertInMiddle(Node* &head, int n, int p){
    Node* newNode = new Node(n);
    if(p==0){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    int c = 1;
    while(temp!=NULL){
        if(c == p ){
            // cout<<temp->val<<endl;
            // cout<<c<<endl;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
        c++;
    }
}

// inset at middle : tutorial code
void insertAtMiddle2(Node* &head, int n, int p){
    if(p==1){
        insertAthead(head,n);
    }
    int c= 1;
    Node* temp = head;
    while(c!=p){
        temp= temp->next;
        c++;
    }

    if(temp->next == NULL){
        insertAtTail(head, n);
    }else{
        Node* newNode = new Node(n);
        newNode->next= temp->next;
        temp->next = newNode;
    }

}

int main(){
    Node* head = new Node(5);
    Node* temp = new Node(7);
    head->next = temp;
    head = insertAthead(head, 11);
    head = insertAtTail(head, 15);
    insertInMiddle(head, 13, 3);
    insertAtMiddle2(head, 16, 4);
    print(head);
    deletenode(head, 2);
    print(head);
}