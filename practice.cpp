#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b){
    vector<vector<int>> t(a.length()+1, vector<int> (a.length()+1, 0));

    for(int i = 0;i<a.length()+1;i++){
        for(int j = 0;j<=a.length()+1;j++){
            if(i==0 or j==0) t[i][j] = 0;
            else if(a[i-1] == b[j-1]){
                t[i][j] = 1+t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[a.length()][a.length()];
}

int main()
{
    string rs = "AGGTAB";
    string s = rs;
    reverse(rs.begin(),rs.end());
    cout<<endl<<lcs(rs,s);
    return 0;
}
