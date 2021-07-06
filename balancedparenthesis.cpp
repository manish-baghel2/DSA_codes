#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) 
{
    stack<char>  st;
    bool ans = false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] =='{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }else if(s[i] == '}')
        {
            if(!st.empty() && st.top()=='{')
            {
                ans = true;
                st.pop();
            }else 
            {
                ans = false;
                return ans;
            }
        }else if(s[i] == ']')
        {
            if(!st.empty() && st.top()=='[')
            {
                ans = true;
                st.pop();
            }else
            {
                return ans = false;
            }
        }else if(s[i] == ')')
        {
            if(!st.empty() && st.top()=='(')
            {
                st.pop();
                ans = true;
            }else
            {
                return ans = false;
            }
        }
    }
    if(!st.empty() && ans == true)
    {
        ans = false;
        return ans;
    }else{
        return ans;
    }        
}

int main()
{
    string s = "(){}";
    if(isValid(s))
    {
        cout<<"it is balanced";
    }else
    {
        cout<<"it is not balanced";
    }
}