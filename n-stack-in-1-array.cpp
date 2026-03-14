#include<bits/stdc++.h>
using namespace std;

class nStack {
    vector<int> arr;
    vector<int> top;
    vector<int> next;
    int freeSpace;
    public: 

    nStack(int n, int s) {
        arr.resize(s);
        top.resize(n);
        next.resize(s);
        for(int i = 0 ; i< n; i++) {
            top[i] = -1;
        }
        for(int i = 0 ; i < s ; i++) {
            next[i] = i+1;
        }
        next[s-1] = -1;
        freeSpace = 0;
    }
    
    // x - value to be pushed, m - index of the stack to which we are going to push the value to
    bool push(int x, int m){
        if(freeSpace == - 1) return false;
        int index = freeSpace;
        freeSpace = next[index];
        next[index] = top[m-1];
        arr[index] = x;
        top[m-1] = index;
        return true;
    }

    // pop function with m(stack) to pop from
    int pop(int m) {
        if(top[m-1] == -1) return -1;
        int index = top[m-1];
        int x = arr[index];
        top[m-1] = next[index];
        next[index] = freeSpace;
        freeSpace = index;
        return x;
    }

};

int main() {
    int n = 3, s = 10;
    nStack ns(n, s);
    ns.push(15, 2);
    ns.push(45, 2);
    cout << ns.pop(2) << endl;
    cout << ns.pop(2) << endl;
    ns.push(17, 1);
    ns.push(49, 1);
    ns.push(39, 1);
    cout << ns.pop(1) << endl;
    cout << ns.pop(1) << endl;
    cout << ns.pop(1) << endl;
    cout << ns.pop(1) << endl;
    return 0;
}