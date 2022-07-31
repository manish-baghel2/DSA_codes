#include<bits/stdc++.h>
using namespace std;
// bool solve(string s1, string s2)
// {
//     vector<vector<bool>> t(s1.length()+1, vector<bool> (s2.length()+1, false));
//     for(int i=0;i<=s1.length();i++)
//     {
//         for(int j=0;j<=s2.length();j++)
//         {
//             if(i==0 || j==0) t[i][j] = 0;
//             else if(s1[i-1] == s2[j-1]) t[i][j] = t[i-1][j-1]+1;
//             else t[i][j] = max(t[i-1][j],t[i][j-1]);
//         }
//     }
//     if(t[s1.length()][s2.length()]==s2.length())
//     {
//     cout<<t[s1.length()][s2.length()];
        
//         return true;
//     }
//     return false;
// }

int main()
{
    // string s1="aadbbcbcac";
    string s3="aadbbcbcac";
    // vector<vector<int>> t(s1.length()+1, vector<int> (s2.length()+1, 0));
    // for(int i=0;i<=s1.length();i++)
    // {
    //     for(int j=0;j<=s2.length();j++)
    //     {
    //         if(i==0 || j==0) {
    //             t[i][j] = 0;
    //         }
    //         else if(s1[i-1] == s2[j-1]) {
    //             t[i][j] = t[i-1][j-1]+1;
    //         }
    //         else {
    //             t[i][j] = max(t[i-1][j],t[i][j-1]);
    //         }
    //     }
    // }

//     "aabcc"
// "dbbca"
// "aadbbcbcac"
string ans = "aac";
int j=0;
    for(int i=0;i<s3.length();i++)
    {
        if(j==ans.length())
            break;
        if(s3[i] == ans[j]) {
            s3.erase(i,1);
            j++;
        }
        cout<<s3<<endl;
    }
    // s2.erase(1,1);
    // cout<<s2;
    cout<<s3;
    return 0;
}