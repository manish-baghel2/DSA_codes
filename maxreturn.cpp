#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, in=0, sell=0, profit=0 ;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(i==0 && ar[i] < ar[i+1])
        {
            in = ar[i];
        }else if(i<n-1 && i>0)
        {
            if(ar[i]<ar[i+1] && ar[i] <ar[i-1])
            {
                in = ar[i];
            }
            if(ar[i]>ar[i+1] && ar[i] > ar[i-1])
            {
                sell = ar[i];
            }
        }if(i == n-1 && ar[i] > ar[i-1])
        {
            sell = ar[i];
        }
        profit += (sell - in);
    }
    cout<<profit<<endl;
}