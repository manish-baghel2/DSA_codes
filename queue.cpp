#include<iostream>
using namespace std;

#define n 20

 class queue
 {
     int* arr;
     int front;
     int back;

     public:
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        void push(int x)
        {
            if(back == n-1)
            {
                cout<<"Queue overflown"<<endl;
                return;
            } 
            back++;
            arr[back] = x;
            if(front == -1)
            {
                front++;
            }
        }

        void pop()
        {
            if(front == -1)
            {
                cout<<"no element in the queue";
                return;
            }
            front++;
        }

        bool empty()
        {
            if(front == -1 or front > back)
            {
                return true;
            }else{
                return false;
            }
        }

        int peek()
        {
            if(front == -1 or front> back)
            {
                cout<<"no elements in the queue";
                return -1;
            }
            return arr[front];
        }
 };

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
}