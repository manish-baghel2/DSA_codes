#include<bits/stdc++.h>
using namespace std;

void subsetsum(int arr[], int sum, int n)
{
    // vector<bool, vector<bool>> k(n+1, vector<bool> (sum+1));
    bool k[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
            {
                k[i][j] = true;
            }else if(i==0 and j!=0)
            {
                k[i][j] = false;
            }else if(arr[i-1] <=sum)
            {
                k[i][j] = k[i-1][j-arr[i-1]] || k[i-1][j];
            }else if(arr[i-1] > sum)
            {
                k[i][j] = k[i-1][j];
            }
        }
    }
    int mn =INT_MAX;
    for(int i=0;i<sum/2;i++)
    {
        if(k[n][i])
        {
            mn = min(mn, sum-2*i);
        }
    }
    cout<<mn<<endl;
}

int main()
{
    int arr[] = {1, 2, 7};
    int sum=0;
    for(int i: arr)
    {
        sum+=i;
    }
    subsetsum(arr, sum, 3);
}