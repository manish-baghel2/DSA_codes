#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n) {
    int max_so_far = INT_MIN;
    int curr_max = 0;
    for(int i = 0; i < n; i ++) {
        curr_max += arr[i];
        cout<<"curr_max : "<<curr_max<<endl;
        if(curr_max > max_so_far) max_so_far = curr_max;
        if(curr_max < 0) curr_max = 0;
    }
    cout<<"max_so_far : "<<max_so_far<<endl;
    return max_so_far;
}

int main() {
    int arr[] = {-6, -5, -70, -4, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    return kadane(arr, n);
}