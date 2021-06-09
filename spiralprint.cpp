#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }   
    }
    int rs = 0, re = n-1, cs = 0, ce = m-1;
    while( rs <= re && cs <= ce){
        for( int col = cs; col<= ce; col++){
            cout<<a[rs][col]<<" ";
        }
        cout<<endl;
        rs++;
        for(int row = rs; row<=re; row++){
            cout<<a[row][ce]<<" ";
        }
        cout<<endl;
        ce--;
        for(int col = ce; col>= cs; col--){
            cout<<a[re][col]<<" ";
        }
        cout<<endl;
        re--;
        for(int row = re; row>=rs; row--){
            cout<<a[row][cs]<<" ";
        }
        cout<<endl;
        cs++;
    }
}