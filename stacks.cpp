#include<bits/stdc++.h>
using namespace std;

#define n 100

class stacks
{
    int* arr;
    int Top;
    public:
        stacks()
        {
            arr = new int[n];
            Top =-1;
        }

        void push(int x)
        {
            if(Top == n-1)
            {
                cout<<"stack if over-flowed"<<endl;
                return;
            }
            Top++;
            arr[Top] = x;
        }

        void pop()
        {
            if(Top == -1)
            {
                cout<<"stack is empty"<<endl;
                return;
            }
            Top--;
        }

        void top()
        {
            if(Top == -1)
            {
                cout<<"stack is empty"<<endl;
                return;
            }
            cout<<arr[Top]<<endl;
        }

        bool empty()
        {
            return Top == -1;
        }
};

int main()
{
    stacks st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    st.top();
    cout<<st.empty()<<endl;
}