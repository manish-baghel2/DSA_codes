#include<bits/stdc++.h>
using namespace std;

vector<int> freqSort(vector<int>& arr) {
    unordered_map<int,int> mp;
    for(auto i : arr) {
        mp[i]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout<<i->second<<" "<<i->first<<endl;
        minh.push({i->second, i->first});
    }
    vector<int> ans;
    while(!minh.empty()) {
        ans.push_back(minh.top().second);
        minh.pop();
    }
    return ans;
}

int main() {
    vector<int> arr = {1,1,2,3,2,2,4};
    vector<int> sortedArr = freqSort(arr);
    for(int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}