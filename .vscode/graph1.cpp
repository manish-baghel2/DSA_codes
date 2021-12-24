#include<bits/stdc++.h>
using namespace std;

void addvertex(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printarray(vector<int> adj[], int V){
    cout<<"/n Adjacent vertices of ";
    for(int i=0;i<V;i++){
        cout<<i;
        for(auto j: adj[i]){
            cout<<" -> "<<j;
        }
        cout<<endl;
    }
}


int main() {
    int V = 5;
    vector<int> adj[V];
    addvertex(adj, 0, 1);
    addvertex(adj, 0, 4);
    addvertex(adj, 1, 4);
    addvertex(adj, 1, 3);
    addvertex(adj, 1, 2);
    addvertex(adj, 2, 3);
    addvertex(adj, 3, 4);
    printarray(adj, V);
}