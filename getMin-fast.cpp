#include<bits/stdc++.h>
using namespace std;

class nStack {
    private:
        stack<int> s;
        int mini;
    public:
        void push(int n) {
            if(s.empty()) {
                s.push(n);
                mini = n;
            } 
            if(n < mini) {
                s.push(2*n - mini);
                mini = n;
            } else {
                s.push(n);
            }
        }

        int pop() {
            if(s.empty()) return -1;
            int curr = s.top();
            s.pop();
            if(curr < mini) {
                int prevMini = mini;
                mini = 2*mini - curr;
                return prevMini;
            } else {
                return curr;
            }
        }

        bool isEmpty(){
            return s.empty();
        }

        int getMin() {
            if(s.empty()) return -1;
            return mini; 
        }
};

int main() {
    nStack ns;
    // Basic test
    ns.push(3);
    ns.push(5);
    cout << ns.getMin() << endl; // Output: 3
    ns.push(2);
    ns.push(1);
    cout << ns.getMin() << endl; // Output: 1
    ns.pop();
    cout << ns.getMin() << endl; // Output: 2
    ns.pop();
    cout << ns.getMin() << endl; // Output: 3

    // Edge case: negative numbers
    ns.push(-4);
    cout << ns.getMin() << endl; // Output: -4
    ns.push(-10);
    cout << ns.getMin() << endl; // Output: -10
    ns.pop();
    cout << ns.getMin() << endl; // Output: -4
    ns.pop();
    cout << ns.getMin() << endl; // Output: 3

    // Edge case: duplicate minimums
    ns.push(3);
    ns.push(3);
    cout << ns.getMin() << endl; // Output: 3
    ns.pop();
    cout << ns.getMin() << endl; // Output: 3
    ns.pop();
    cout << ns.getMin() << endl; // Output: 3

    // Edge case: pop all elements
    while (!ns.isEmpty()) ns.pop();
    // Try getMin on empty stack
    cout << "Stack empty, getMin: " << ns.getMin() << endl;
    return 0;
}