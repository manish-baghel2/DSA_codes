// program for making queue using linked list
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node* front ;
    node* back;

    public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int val)
    {
        node* n = new node(val);
        if(front == NULL and back == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop()
    {
        if(front == NULL)
        {
            cout<<"the queue is empty"<<endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
       if(front == NULL)
        {
            cout<<"the queue is empty"<<endl;
            return front->data;
        }
        return front->data;
    }

    bool empty()
    {
        if(front == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.peek()<<" ";
    q.pop();
    cout<<q.peek()<<" ";
    q.pop();
    cout<<q.peek()<<" ";
    q.pop();
    cout<<q.peek()<<" ";
    q.pop();
    cout<<q.peek()<<" ";
    q.pop();
    cout<<q.peek()<<" ";
    q.pop();
    cout<<q.empty()<<endl;
}