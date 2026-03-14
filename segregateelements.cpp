#include<bits/stdc++.h>
using namespace std;

void segregateElements(vector<int>& arr) {
    // Your code goes here
    vector<int> tmp;
    for(auto i : arr) {
        if(i >= 0) tmp.push_back(i);
    }
    for(auto i: arr) {
        if(i <0) tmp.push_back(i);
    }
    for(int i = 0; i < arr.size(); i ++) {
        arr[i] = tmp[i];
    }
}

int main() {
    vector<int> arr = {12, -7, 5, -3, 8, -1};
    segregateElements(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}