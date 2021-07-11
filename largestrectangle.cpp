#include<bits/stdc++.h>
#include<math.h>
using namespace std;

// nearest smallest right
vector<int> NSR(vector<int> v)
{
    stack<int> st;
    vector<int> ans;
    int Default = v.size();

    for(int i=v.size()-1;i>=0;i--)
    {
        if(st.empty())
        {
            st.push(Default);
        }else if(!st.empty() and v[st.top()]>= v[i])
        {
            while(!st.empty() and v[st.top()] >= v[i])
            {
                st.pop();
            }

            if(st.empty())
                st.push(Default);
        }
        ans.push_back(st.top());
        st.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// nearest smallest left
vector<int> NSL(vector<int> v)
{
    int Default =-1;
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<v.size();i++)
    {
        if(st.empty())
        {
            st.push(Default);
        }else if(!st.empty() and v[st.top()] >= v[i])
        {
            while(!st.empty() and v[st.top()] >=v[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(Default);
            }
        }
        ans.push_back(st.top());
        st.push(i);
    } 
    return ans;
}

void maxarea(vector<int> v)
{
    int maxArea=0, currarea;
    vector<int> ll = NSL(v);
    vector<int> rl = NSR(v);
    vector<int> width;

    for(int i=0;i<v.size();i++)
    {
        width.push_back(rl[i] - ll[i] -1);
        currarea = width[i]*v[i];
        maxArea = max(maxArea, currarea);
    }

    cout<<maxArea<<endl;
}

int main()
{
    vector<int> v = {6, 2, 5, 4, 5, 1, 6};
    maxarea(v);
}