#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "00211e11d2dc2bce6f00057c120bf8c7365e00cd46c5b37475bb13000b85f1c2a8fcf64a";
    int n = 64;
    int string_length = n/4;
    int leading_zeros = 18 - string_length;
    vector<string> ans;
    int start = leading_zeros;
    for(int i = 0; i<4; i++) {
        ans.push_back(s.substr(start, string_length));
        start = start + string_length + leading_zeros;
    }
    for(auto i: ans) cout<<i<<std::endl;
    return 0;
}