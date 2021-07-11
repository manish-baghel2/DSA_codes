#include<bits/stdc++.h>
using namespace std;

class Stack 
{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    Stack()
    {
        N=0;
    }
    // void push(int x)
    // {
    //     q2.push(x);
    //     while(!q1.empty())
    //     {
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
        
    //     queue<int> temp = q1;
    //     q1= q2;
    //     q2 = temp;
    //     N++;
    // }

    // int pop()
    // {
    //     if(q1.empty() and q2.empty())
    //     {
    //         cout<<"no element in the stack"<<endl;
    //         return -1;
    //     }
    //     int res = q1.front();
    //     q1.pop();
    //     N--;
    //     return res;
    // }

    // int index()
    // {
    //     return N;
    // }

    // implementing stack using queue by making pop a costly operation
    void push(int val)
    {
        q1.push(val);
        N++;
    }

    void pop()
    {
        if(q1.empty())
        {
            return;
        }
        while(q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();

        queue<int> temp = q1;
        q1= q2;
        q2 = temp;
        N--;
    }

    int top()
    {
        if(q1.empty())
        {
            return -1;
        }
        while(q1.size() != -1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int term = q1.front();
        q1.pop();
        queue<int> temp = q1;
        q1= q2;
        q2 = temp;
        q1.push(term);
        return term;
    }

    bool empty()    
    {
        if(q1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}