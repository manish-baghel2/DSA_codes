#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

// // print the stack
// void printstack(stack<int> st)
// {
//     while(!st.empty())
//     {
//         cout<<st.top()<<endl;
//         st.pop();
//     }
// }

// // inserting the element in the end in the bottom of the stack
// void insertatbottom(stack<int> &st, int ele)
// {
//     if(st.empty())
//     {
//         st.push(ele);
//         return;
//     }
//     int topele = st.top();
//     st.pop();
//     insertatbottom(st, ele);
//     st.push(topele);
// }

// // reversing the stack
// void reversestack(stack<int> &st)
// {
//     if(st.empty())
//     {
//         return;
//     }
//     int ele = st.top();
//     st.pop();
//     reversestack(st);
//     insertatbottom(st, ele);
// }

// prefix evaluation of a equation
int prefixevaluation(string s)
{
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--)
    {
        int op1, op2;
        if(s[i] >= '0' && s[i]<= '9')
        {
            st.push(s[i]-'0');
        }else
        {
            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

// postfix evaluation of any equation
int postfixevaluation(string s)
{
    stack<int> st;
    for(int i=0;i<=s.length()-1;i++)
    {
        int op1, op2;
        if(s[i] >= '0' && s[i]<= '9')
        {
            st.push(s[i]-'0');
        }else
        {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}

// precedence checher
int prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// program for infixtopostfix conversion
void infixtopostfix(string s)
{
    string res;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z'))
        {
            res+=s[i];
        }else if(s[i] == '(')
        {
            st.push(s[i]);
        }else if(s[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }else
        {
            while(!st.empty() && prec(st.top())>prec(s[i]))
            {
                res+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    cout<<res<<endl;
}

// program for infixtoprefix conversion
void infixtoprefix(string s)
{
    string res;
    stack<char> st;
    for(int i=s.length()-1;i>=0;i--)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z'))
        {
            res+=s[i];
        }else if(s[i] == ')')
        {
            st.push(s[i]);
        }else if(s[i] == '(')
        {
            while(!st.empty() && st.top() != ')')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }else
        {
            while(!st.empty() && prec(st.top())>=prec(s[i]))
            {
                res+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    for(int i=res.length()-1;i>=0;i--)
    {
        cout<<res[i];
    }cout<<endl;
}

// balanced parenthesis program
void balancedparenthesis(string s)
{
    stack<char> st;
    bool ans = false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == '{' or s[i] == '[' or s[i] == '(')
        {
            st.push(s[i]);
        }else if(s[i] == '}')
        {
            if(!st.empty() and st.top() == '{')
            {
                st.pop();
                ans = true;
            }else
            {
                ans = false;
            }
        }else if(s[i] == ']')
        {
            if(!st.empty() and st.top() == '[')
            {
                st.pop();
                ans = true;
            }else
            {
                ans = false;
            }
        }else if(s[i] == ')')
        {
            if(!st.empty() and st.top() == '(')
            {
                st.pop();
                ans = true;
            }else
            {
                ans = false;
            }
        }
    }
    if(ans and st.empty())
    {
        cout<<"it is balanced"<<endl;
    }else
    {
        cout<<"it is not balanced"<<endl;
    }
}

int main(){
    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);

    // reversestack(st);
    string s = "(a-b/c)*(a/k-l)";
    // cout<<prefixevaluation("-+7*45+20")<<endl;
    // cout<<postfixevaluation("745*+20+-")<<endl;
    // cout<<postfixevaluation("46+2/5*7+")<<endl;
    // infixtopostfix(s);
    infixtoprefix(s);
    // printstack(st);
    balancedparenthesis("{[([])]}");
}