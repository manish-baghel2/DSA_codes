#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int  i=0;i<n-1;i++)
    {
        if(ar[i+1] != ar[i]+1)
        {
            cout<<ar[i]+1;
            return 0;
        }
    }
}