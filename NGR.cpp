#include<bits/stdc++.h>
using namespace std;

vector<int> NGL(vector<int> arr)
{
    stack<int> st;
    vector<int> ans;
    int n = arr.size();

    for(int i=n-1;i>=0;i--)
    {
        // my solution
        // while(!st.empty() and arr[i] >st.top())
        // {
        //     st.pop();
        // }
        // if(!st.empty())
        // {
        //     ans.push_back(st.top());
        // }else{
        //     ans.push_back(-1);
        // }
        // st.push(arr[i]);

        // suggested solution in the video youtube.com/watch?v=NXOOYYwpbg4
         

    }

    reverse( ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans = NGL(arr);
    for(auto i: ans)
        cout<<i<<" ";
}