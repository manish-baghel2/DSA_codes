#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int n = s.size() / 2 - 1;
    cout<<n<<endl;
    for (int i = 0; i <= n; i++) {
        int tmp = int(s[i]) + int(s[s.size()-1 - i]);
        s[i] = char(tmp - int(s[i]));
        s[s.size()-1-i] = char(tmp - int(s[i]));
    }
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (char c : s) {
        cout << c;
    }
    return 0;
}