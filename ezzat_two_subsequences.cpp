#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;cin>>n;
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            int s;
            cin>>s;
            v.push_back(s);
        }
        int sum1=0, sum2=0;
        for(int t=0;t<n-1;t++)
        {
            sum1+=v[i];
            for(int j=i+1;j<n;j++)
            {
                sum2+=v[j];
            }
            double avg = (double)sum1/(t+1) + (double)sum2/(n-t+1);
        }
    }
}