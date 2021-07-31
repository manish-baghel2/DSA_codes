#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> v(n);
    for(auto &i:v)
    {
        cin>>i;
    }

    int i=0, ans =0, count=0;
    for(int j=0;j<n;j++)
    {
        if(v[j] == 0)
        {
            count++;
        }
        while(count > k)
        {
            count--;
            i++;
        }
        ans = max(ans, j-i+1);
    }
    cout<<ans;
}