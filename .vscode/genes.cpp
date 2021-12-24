#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[2];
    for(int i=0;i<2;i++){
        cin>>s[i];
    }
    char b;
    for(char i:s){
        if(i == 'R'){
            b = i;
            break;
        }else if(i == 'B'){
            if(s[1] == 'R'){
                b = s[1];
                break;
            }else {
                b = i;
                break;
            }
        }else if(i == 'G'){
            b = s[1];
            break;
        }
    }
    cout<<b;
}