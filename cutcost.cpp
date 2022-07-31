#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &t)
{
    if(i>=j or abs(i-j) == 1)
    {
        return 0;
    }
    if(t[i][j] != -1)
    {
        return t[i][j];
    }
    int mn = INT_MAX;
    for(int k=0;k<cuts.size();k++)
    {
        if(cuts[k] == i or cuts[k] == j) continue;
        int temp = j-i + solve(cuts, i, k, t) + solve(cuts, k, j, t);
        mn = min(mn, temp); 
   }
    cout<<t[i][j]<<endl;
    return t[i][j] = mn;
}

int main(){
	int n=7;
	vector<int> cuts = {1,3,4,5};
	vector<vector<int>> t(n+1, vector<int> (n+1, -1));
    return solve(cuts, 0, n, t);
}