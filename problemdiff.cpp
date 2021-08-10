#include<bits/stdc++.h>
using namespace std;

int sets(vector<int> v)
{
    cout<<"this is called"<<endl;
    int set = 2;
    vector<int> idx(11, 0);
    for(auto i:v)
    {
        idx[i]++;
        if(idx[i] == 3)
        {
            set = 1;
        }else if(idx[i] == 4)
        {
            set == 0;
        }
    }
    return set;
}

int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        vector<int> v;
        for(int j=0;j<4;j++)
        {
            cin>>v[j];
        }
        cout<<sets(v)<<endl;
    }
}