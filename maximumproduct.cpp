#include<bits/stdc++.h>
using namespace std;

// sorting
void sorting(int ar[], int n)
{
    for(int i=1;i<n;i++)
    {
        int current = ar[i];
        int j= i-1;
        while(ar[j]<current && j>=0)
        {
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1]= current;
    }
}

// max product
void maxprod(int ar[], int n)
{
    int nc=0;
    sorting(ar,n);
    for(int i;i<n;i++)
    {
        if(ar[i]<0)
            nc++;
    }
    if(nc !=0)
    {
        int t=0;
        if(nc%2 == 0)
        {
            t=nc;   
        }else{
            t =nc-1;
        }
        for(int i=n-1;i>t;i--)
        {
            if(ar[i]<0)
            {
                ar[i]=-ar[i];
            }
        }
        sorting(ar, n);
    }
    
    int maxprod=1;
    for(int i=0;i<3;i++)
    {
        maxprod = maxprod*ar[i];
    }
    cout<<maxprod;
}

int main()
{
    int n,nc;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    maxprod(ar, n);
}