#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *adj;
    bool *visited;
    public:
    graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    void addedge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void bfs(int s){
        visited = new bool[v];
        for(int i=0;i<v;i++){
            visited[i] = false;
        }

        list<int> queue;
        visited[s] = true;
        queue.push_back(s);

        list<int>::iterator i;

        while(!queue.empty()){
            s = queue.front();
            cout<<s<<" -> ";
            queue.pop_front();
            for(i = adj[s].begin(); i!=adj[s].end();i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

int main(){
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(1, 4);
    g.addedge(1,3);
    g.addedge(1,2);
    g.addedge(3,4);
    g.addedge(3,2);
    g.bfs(2);
}