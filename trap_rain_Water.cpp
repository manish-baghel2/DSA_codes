#include<bits/stdc++.h>
using namespace std;

// local maxima index function
vector<int> LMI(vector<int> v, int n)
{
    vector<int> ans;

    for(int i=0; i<n ;i++)
    {
        if((i==0 and v[i]>v[i+1]) or ( i== n-1 and v[i]>v[i-1]))
        {
            ans.push_back(i);
        }else if( v[i] > v[i+1] and v[i] > v[i-1])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// calculator for trap water
// void trapans(vector<int> v, int n)
// {
//     vector<int> m = LMI(v, n);
//     int height = 0, t=0, start =-1;
//     int ans=0, water;
//     for(int i=0;i<n;i++)
//     {
//         if(i==m[t] and t<m.size())
//         {

//             // cout<<"index = "<<i<<endl;   
//             if(v[m[t]] > v[m[t+1]])
//             {
//                 height = v[m[t+1]];
//             }else
//             {
//                 height = v[m[t]];
//             }
//             start = m[t];
//             t++;
//             // cout<<"start = "<<start<<endl;
//         }else if(i>start and start >= 0 and i<m[t])
//         {
//             ans += height - v[i];
//         }
//     }
//     cout<<ans<<endl;
// }

void trapans(vector<int> v, int n)
{
    stack<int> st;
    int diff =0, ans =0;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() and v[st.top()] < v[i])
        {
            int curr = st.top();
            st.pop();
            if(st.empty())
            {
                break;
            }
            diff = i - st.top() -1;
            ans += (min(v[st.top()], v[i])-v[curr])*diff;
        }
        st.push(i);
    }
    cout<<ans<<endl;

}

int main()
{
    // vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> v = {0,1,2,3,4,0,2,1,0,3,2,4,1,2};
    trapans(v, v.size());
}