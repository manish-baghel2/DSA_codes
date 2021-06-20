#include<bits/stdc++.h>
#include<stack>
using namespace std;

void reversesentence(string s)
{
    stack<string> str;
    for(int i=0;i<s.length();i++)
    {
        string word = "";
        while(s[i]!= ' ' && i != s.length())
        {
            word += s[i];
            i++;
        }
        str.push(word);
    }

    while(!str.empty())
    {
        cout<<str.top()<<" ";
        str.pop();
    }
    cout<<endl;
}

int main()
{
    string s ="hey , how are you doing ?";
    reversesentence(s);
}