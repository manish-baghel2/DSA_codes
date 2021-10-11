#include<bits/stdc++.h>
using namespace std;

int t[102][1002];
memset(t, -1, sizeof(t));

int knapsack(int* wt, int* v, int w, int n)
{
    if(n==0 or w==0)
    {
        return 0;
    }
    if(t[n][w] != 0)
    {
        return t[n][w];
    }
    if(wt[n-1] <= w)
    {
        return t[n][w] = max((v[n]+knapsack(wt, v, w-wt[n-1], n-1)), knapsack(wt, v, w, n-1));
    }else if(wt[n-1] > w)
    {
        return t[n][w] = knapsack(wt, v, w, n-1);
    }
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int v[] = {1, 4, 5, 7};
    int w=7;
    int n=4;
    cout<<knapsack(wt, v, w, n);
}