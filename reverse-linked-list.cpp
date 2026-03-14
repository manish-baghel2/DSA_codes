#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head;
        while(curr != nullptr) {
            prev = head;
            head = curr;
            curr = curr->next;
            head->next = prev;
        }
        return head;
    }
    
    int main() {
        Solution solution;
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        head = solution.reverseList(head);
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        return 0;
    }
};
