#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int N = 1e6+2;
    int check[N];
    for(int i=0;i<N;i++)
    {
        check[i] = -1;
    }
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n;i++)
    {
        check[ar[i]] = 0;
    }
    for(int i=ar[0];i<N;i++)
    {
        if(check[i] == -1)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}