#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    int ar[n];
    string ar1[n];
    float ar2[n];
    for(int i = 0; i < n; i++ ){
        for(int j = i; j < n; j++){
            if( ar[j] < ar[i] ){
                ar[i] = ar[j];
            }else
        }
    }
}