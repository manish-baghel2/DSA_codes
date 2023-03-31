#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n;
    cout<<"enter "
    cin>>n;
    int count = 0;
    while(count< n){
        for(auto j: arr){
            cout<<j<<" ";
        }
        for(int j=n-1;j>0;j--){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
        count ++;
        cout<<endl;
    }
    return 0;
}