#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=1;i<n;i++){
        int curr = ar[i];
        int j = i-1;
        while(ar[j] > curr && j>= 0){
            ar[j+1] = ar[jf];
            j--;
        }
        ar[j+1] = curr;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    
}