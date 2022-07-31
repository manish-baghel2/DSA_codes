#include<bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2, vector<vector<int>> &t, int m, int n)
{
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i==0 or j==0)
            {
                t[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                t[i][j] = 1+t[i-1][j-1];
            }else
            {
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
}

// string shortestCommonSupersequence(string str1, string str2) {
//     int m = str1.length(), n=str2.length();
//     vector<vector<int>> t(m+1, vector<int> (n+1, -1));
//     lcs(str1, str2, t, m, n);
//     // int i=m, j=n;
//     // string ans = "";
//     // while(i>0 and j>0)
//     // {
//     //     if(str1[i] == str2[j])
//     //     {
//     //         ans += str1[i];
//     //         i--;j--;
//     //     }else
//     //     {
//     //         if(t[i-1][j] > t[i][j-1])
//     //         {
//     //             ans += str1[i-1];
//     //             i--;
//     //         }else
//     //         {
//     //             ans += str2[j-1];
//     //             j--;
//     //         }
//     //     }
//     // }
//     // string s1 = "";
//     // for(int i=ans.length()-1;i<=0;i--)
//     // {
//     //     s1+=ans[i];
//     // }
//     cout<<t[m][n];
//     return " ";
// }

int main()
{
    string s1 = "abac";
    string s2 = "cab";
    int m = s1.length();
    int n = s2.length();
    cout<<m<<' '<<n;
    vector<vector<int>> t(m+1, vector<int> (n+1, -1));
    lcs(s1, s2, t, m, n);
    // string ans = shortestCommonSupersequence(s1, s2);
    cout<<t[m-1][n-1];
    return 0;
}