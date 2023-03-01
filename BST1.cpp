#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    bool isCircular(Node* root){
        Node* slow = root;
        Node* fast = root;
        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            // cout<<fast->data<<endl;
            if(fast == slow) return 1;
        }
        return 0;
    }
};



// Create a circular linked list with n nodes
Node* createCircularLinkedList(int n) {
    Node* head = new Node;
    head->data = 1;
    head->next = nullptr;

    Node* curr = head;

    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node;
        newNode->data = i;
        newNode->next = nullptr;

        curr->next = newNode;
        curr = newNode;
    }

    // Make the list circular by connecting the last node to the head
    curr->next = head;

    return head;
}

int main() {
    int n = 5; // Number of nodes in the list

    Node* head = createCircularLinkedList(n);

    // Traverse the circular linked list
    cout << "Circular Linked List with cycle at end:" << endl;

    Node* curr = head;

    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);

    cout << endl;
    cout<<head->isCircular(head)<<endl;

    return 0;
}
