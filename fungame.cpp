#include<bits/stdc++.h>
#include<stack>
using namespace std;

void fungame(int arr[])
{
    stack <int> st;
    int i=0, j=2, n=0;
    while(i<=2 && j>=0)
    {
        n++;
        if(arr[i] > arr[j])
        {
            j--;
            st.push(1);
        }else if(arr[i] < arr[j]){
            i++;
            st.push(2);
        }else{
            st.push(0);
            i++;
            j--;
        }
    }
    int ans[n];
    i=0;
    while(i<=2 && !st.empty())
    {
        ans[i] = st.top();
        st.pop();
        i++;
    }
    for(int t=i-1;t>=0;t--)
    {
        cout<<ans[t]<<" ";
    }cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    fungame(arr);
}