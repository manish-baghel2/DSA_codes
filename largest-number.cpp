#include<bits/stdc++.h>
using namespace std;

string largestnum(vector<int> v)
{
    string temp;
    // for(int i=0;i<v.size();i++)
    // {
    //     for(int j=i;j<v.size();j++)
    //     {
    //         if((v[i]+v[j])<(v[j]+v[i]))
    //         {
    //             temp =v[i];
    //             v[i] = v[j];
    //             v[j] = temp;
    //         }   
    //     }
    // }
    
    string ans="";
    for(auto i: v)
    {
        ans += i;
    }
    return ans;
}

int main()
{
    vector<string> v={"3", "30", "34", "5", "9"};
    // string s = largestnum(v);
    // cout<<s<<endl;
    vector<string> a = v;
    for(auto i:v)
    {
        cout<<i;
    }
}