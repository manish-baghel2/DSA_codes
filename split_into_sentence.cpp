#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    bool isSafe(string& str, vector<string>& dict) {
        for(auto i : dict) {
            if(str == i) return true;
        }
        return false;
    }
    void solve(int i, string& sent, vector<string>& ans, vector<string>& dict, string& s) {
        if(i == s.length()) {
            ans.push_back(sent);
            return;
        }
        for(int idx = i; idx<s.length();idx++) {
            string temp = s.substr(i, idx-i+1);
            if(isSafe(temp, dict)) {
                sent += " " + temp;
                solve(idx+1, sent, ans, dict, s);
                // sent.pop_back();
                sent.erase(sent.length()-(temp.length()+1));
            }
        }
    }
    vector<string> wordBreak(vector<string>& dict, string& s) {
        // code here
        vector<string> ans;
        string sent = "";
        solve(0, sent, ans, dict, s);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> dict = {"i", "like", "sam", "sung", "mobile", "ice", "cream", "man", "go", "mango"};
    string s = "ilike";
    vector<string> result = sol.wordBreak(dict, s);
    for(const string& sentence : result) {
        cout << sentence << endl;
    }
    return 0;
}