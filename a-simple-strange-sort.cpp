#include<bits/stdc++.h>
using namespace std;

bool sorttest(vector<int> v)
{
    stack<int> s;
    s.push(v[v.size()-1]);
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<v[i-1])
        {
            return false;
        }
    }
}

void f(vector)

int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;cin>>n;
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            cin>>v[j];
        }
        bool sorted = false;
        while(sorted)
        {
            for(int j=0;j<n;j++)
            {
                f(v, i);
            }
            sorted = sorttest(v);
        }
    }
}