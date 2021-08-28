#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] ={20, 60, 3, 13, 30};
    map<int, int> g;
    for(int i=0;i<5;i++)
    {
        g.insert(i+1, arr[i]);
    }
    g.erase(2);
    bool find = g.find(50);
    if(find)
    {
        cout<<endl<<"we have 50 in map"<<endl;
    }else{
        cout<<"we dont have 50 in the map"<<endl;
    }
    cout<<g.getrandom
}