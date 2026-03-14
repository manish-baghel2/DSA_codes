#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    // Code here
    if(arr.size() == 1) return arr[0];
    int maxsum = 0, currsum = 0;
    for(auto i : arr) {
        currsum += i;
        if(currsum < 0) currsum = 0;
        if(currsum > maxsum) maxsum = currsum;
    }
    return maxsum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubarraySum(arr) << endl;
    return 0;
}