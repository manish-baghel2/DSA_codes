#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string& s) {
    // code here
    int left = 0, right = s.size()-1;
         bool ans = true;
         
        while (left < right) {
            if(s[left] != s[right]) ans = false;
            left++;
            right--;
        }
        return ans; 
}

int main() {
    string s = "racecar";
    if (isPalindrome(s)) {
        cout << s << " is a palindrome." << endl;
    } else {
        cout << s << " is not a palindrome." << endl;
    }
    return 0;
}