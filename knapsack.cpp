#include <bits/stdc++.h>
using namespace std;

int knapsack(int w, int wt*, int val*, int n)
{
    vector<vector<int>> k( n+1, vector<int>(w+1) );

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0 || j==0)
            {
                k[i][j] = 0;
            }else if(wt[i] > w)
            {
                k[n][w] = 
            }
        }
    }
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << knapSack(W, wt, val, n);
     
    return 0;
}

