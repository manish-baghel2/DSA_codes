#include<bits/stdc++.h>
using namespace std;

void printgraph(vector<vector<int>> adj, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<":"<<" ";
		for(int j: adj[i]
)		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

void addedge(vector<vector<int>>& adj, int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int n=4;
	vector<vector<int>> adj(n);
	addedge(adj, 0, 1);
	addedge(adj, 0,2);
	addedge(adj, 1, 2);
	addedge(adj, 2,3);
	printgraph(adj, n);
}