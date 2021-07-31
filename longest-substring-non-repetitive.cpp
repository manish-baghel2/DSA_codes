#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> dict(256, -1);
    int start = -1, maxlen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        cout<<start<<endl;
        if (dict[s[i]] > start)
        {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxlen = max(maxlen, i - start);
    }
    cout << maxlen;
}