#include<bits/stdc++.h>
using namespace std;

int celebrityPattern(vector<vector<int>>& M, int n){
    stack<int> s;
    for(int i = 0; i<n;i++) {
        s.push(i);
    }
    while(s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top(); 
        s.pop();
        if(M[a][b] == 1) {
            s.push(b);
        } else {
            s.push(a);
        }
    }
    int ans = s.top();
    int rowCount = 0, colCount = 0;
    for(int i = 0 ; i<n; i++) {
        if(M[ans][i] == 0) colCount++;
        if(M[i][ans] == 1) rowCount++;
    }
    if(colCount != n && rowCount != n-1) return -1;
    return ans;
}

int main() {
    int n = 3;
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int celeb = celebrityPattern(M, n);
    cout << "Celebrity is: " << celeb << endl;
    return 0;
}