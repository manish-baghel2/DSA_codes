#include<bits/stdc++.h>
using namespace std;

// ranges for the array
void ranges(int arr[], int n)
{
    int ini = arr[0],end;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[i-1]+1 && i!=0)
        {
            end = arr[i-1];
            if(ini == end)
            {
                cout<<end<<endl;
            }else
            {
                cout<<ini<<"->"<<end<<endl;
            }
            ini = arr[i];
        }
    }
    if(ini>end)
    {
        cout<<ini<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    ranges(ar, n);
}