#include<bits/stdc++.h>
#include<deque>
using namespace std;

int main()
{
    deque<int> q;
    
    vector<int> ans;
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    
    for(int i=0;i<k;i++)
    {
        while(!q.empty() and a[q.back()] < a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(a[q.front()]);

    for(int i=k;i<n;i++)
    {
        if(!q.empty() and q.front() == i-k)
        {
            q.pop_front();
        }

        while(!q.empty() and a[q.back()] < a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for(auto i:ans)
    {
        cout<<i<<" ";
    }cout<<endl;
}
