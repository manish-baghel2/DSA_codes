#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   int n, m, s;
   cin>>n>>m;
   int ar[n][m];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cin>>ar[i][j];
       }
   }
   cin>>s;
   // SEARCHING ALGORITHM
   int i=0, j=m-1;
   bool f=false;
   while (i<n && j>=0)
   {
       if(ar[i][j] == s)
       {
           f=true;
       }
       else if(ar[i][j] > s)
       {
           j--;
       }
       else
       {
           i++;
       }
   }
   if(f)
   {
       cout<<" element exists";
   }else
   {
       cout<<"element does not exists";
   }
}
