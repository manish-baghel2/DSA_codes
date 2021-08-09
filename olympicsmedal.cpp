#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int sum1=0,sum2=0;
        for(int j=0;j<6;j++)
        {
            int s;
            cin>>s;
            if(j<3)
            {
                sum1+=s;
            }
            if(j>=3 and j<6)
            {
                sum2+=s;
            }
        }
        if(sum1>sum2)
        {
            cout<<"1"<<endl;
        }else 
        {
            cout<<"2"<<endl;
        }
    }
    
}