#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast) {
            if(fast == slow) {
                cout<<"fast is null"<<endl;
                return true;
            }
            slow = slow ? slow->next : nullptr;
            fast = fast->next ? fast->next->next : nullptr;
            cout<<slow->val<<endl;
            cout<<fast->val<<endl;
        }
        return false;
    }

    // int main() {
    //     Solution solution;
    //     ListNode* head = new ListNode(1);
    //     head->next = new ListNode(2);
    //     head->next->next = new ListNode(3);
    //     head->next->next->next = new ListNode(4);
    //     head->next->next->next->next = new ListNode(5);
    //     cout << (solution.hasCycle(head) ? "Cycle detected" : "No cycle detected") << endl;
    //     return 0;
    // }
};

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << (solution.hasCycle(head) ? "Cycle detected" : "No cycle detected") << endl;
    return 0;
}