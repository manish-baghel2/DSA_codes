#include<bits/stdc++.h>
using namespace std;

// total poisioned time
void totalattacktime(int ar[], int n, int d)
{
    int dur = 0, end;

    for(int i=0;i<n;i++)
    {
        if(ar[i]<=end && i!=0)
        {
            dur = dur - (end-(ar[i]-1))+d;
            end = ar[i]-1+d;
        }else
        {
            end = ar[i]+d-1;
            dur+=d;
        }
    }
    cout<<dur<<endl;
}

int main()
{
    int n,d;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cin>>d;
    totalattacktime(ar, n, d);
}