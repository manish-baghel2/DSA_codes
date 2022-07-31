#include<bits/stdc++.h>
using namespace std;

void lcs(string s, string r, vector<vector<int>> &t)
{
    // int mx = INT_MIN;
    for(int i=1;i<s.length()+1;i++)
    {
        for(int j=1;j<s.length()+1;j++)
        {
            if(s[i-1]==r[j-1])
            {
                t[i][j] = 1+t[i-1][j-1];
            }else
            {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
            // mx = max(mx, t[i][j]);
        }
    }
    // t[s.length()][s.length()]=mx;
}

string longestPalindrome(string s) {
        string r=s;
        for(int i=0;i<s.length()/2;i++)
        {
            swap(r[i], r[r.length()-i-1]);
        }
        vector<vector<int>> t(s.length()+1, vector<int> (s.length()+1, 0));
        lcs(s, r, t);
        int i = s.length();
        int j = i;
      	string ans = "";
        string temp = "";
        while(i>0 and j>0)
          {
            if(s[i-1] == r[j-1])
            {
                temp += s[i-1];
                i--;
                j--;
            }else if(t[i-1][j] > t[i][j-1])
            {
                temp = "";
                i--;
            }else if(t[i-1][j] < t[i][j-1])
            {
                temp = "";
                j--;
            }
            ans = max(temp, ans);
          }
        cout<<t[s.length()][s.length()]<<" ";
        cout<<ans;
        return ans;
    }

int main()
{
	string s = "babad";
	cout<<longestPalindrome(s);
    return 0;
}