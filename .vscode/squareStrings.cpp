#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string s, ans;
        cin>>s;
        int n = s.length();
        if(n%2==0){
            n = n/2;
            string s1 = s.substr(0, n);
            string s2 = s.substr(n, 2*n-1);
            if(s1 == s2){
                ans = "YES";
            }else {
                ans = "NO";
            }
        }else {
            ans = "NO";
        }
        cout<<ans;
    }
}