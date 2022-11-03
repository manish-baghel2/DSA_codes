#include<bits/stdc++.h>
using namespace std;

int solve(string s, string key){
    vector<vector<int>> t(s.length()+1, vector<int> (key.length()+1, 0));
    int len = 0;
    int row, col;
    for(int i =1;i<= s.length() ; i++){
        for(int j=1;j<=key.length();j++){
            if(s[i-1] == key[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }else{
                t[i][j] = 0;
            }
            if(len < t[i][j]){
                len = t[i][j];
                row = i;
                col = j;
            }
        }
    }

    if(row >= s.length() or s[row] == ' '){
        return 1;
    }else return 0;
}

void test(vector<string> v){
    v.erase(v.begin()+2);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}


int main(){
    // vector<string> s;
    // s.push_back("this is a test");
    // s.push_back("testing for content indexing");
    string key = "content";
    vector<string> v  = {"string 1", "string 2", "string 3", "string 4", "string 5", "string 6", "string 7", "string 8"};
    test(v);
    cout<<"real string :"<<endl;
    for(int i = 0 ;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    // if(solve(s[0], key)){
    //     cout<<s[0]<<endl;
    // }else if(solve(s[1],key)){
    //     cout<<s[1]<<endl;
    // }
    // for(int i=0; i<s.size();i++){
    //     if(solve(s[i],key)) cout<<s[i]<<endl;
    // }

}