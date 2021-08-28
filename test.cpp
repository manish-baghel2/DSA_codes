
// this is a scrap file just there to test various code snippets or syntax to verify there functionalities
#include<bits/stdc++.h>
using namespace std;

// int maxSubArray(const vector<int> A)
// {
//     int sum=0, maxsum =INT_MIN, i=0;
//     while(i<A.size())
//     {
//         sum+=A[i];
//         maxsum = max(sum, maxsum);
//         i++;
//         if(sum<0)
//         {
//             sum=0;
//         }
//     }
//     return maxsum;
// }
void matrix(vector<vector<int>> A)
{
    int rs=0, re=A.size()-1, cs = 0, ce= A[0].size()-1;
    while(rs<=re and cs <= ce)
    {
        for(int i=rs;i<=re;i++)
        {
            cout<<A[cs][i]<<" ";
        }
        cs++;
        for(int i=cs;i<=ce;i++)
        {
            cout<<A[i][re]<<" ";
        }
        re--;
        for(int i=re;i>=rs;i--)
        {
            cout<<A[ce][i]<<" ";
        }
        ce--;
        for(int i=ce;i>=cs;i--)
        {
            cout<<A[i][rs]<<" ";
        }
        rs++;
    }
}

int solution(vector<int> &A, int S) {
    // write your code in C++14 (g++ 6.2.0)
    int sumarray[A.size()];
    int count =0;
    int n = A.size();
    for(int i=0;i<n;i++)
    {
        sumarray[i] = A[i];
        if(sumarray[i] == S)
        {
            count++;
        }
        int sum =0;
        for(int j=i+1;j<n;j++)
        {
            sum = sumarray[j-1]+A[j];
            if((double)sum/(j-i+1) == S)
                count++;
        }
    }
    return count;
}

void display(vector<vector<int>> board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }
}

int main()
{
    // vector<vector<int>> A = {
    //                             // { 1, 2, 3 },
    //                             // { 4, 5, 6 },
    //                             // { 7, 8, 9 }
    //                             {1}
    //                         };
    // // vector<int> A ={-500};
    // // int num = maxSubArray(A);
    // // cout<<num;
    // // matrix(A);
    // string n = "1", m = "21", temp;
    // temp = n+m;
    // cout<<temp;
    // vector<int> v = {2, 1, 3};
    // int k = 2;
    // int ans = solution(v, k);
    // cout<<ans;
    // vector<vector<int>> v;
    // for(int i=0;i<5;i++)
    // {
    //     // for(int j=0;j<4;j++)
    //     // {
    //     //     int s;
    //     //     cin>>s;
    //     //     v[i][j] = s;
    //     // }
    //     int s;
    //     cin>>s;
    //     v[i] = s;
    // }
    // int i, j;cin>>i;cin>>j;
    // int v[i][j];
    // for(int a=0;a<i;a++)
    // {
    //     for(int b=0;b<j;b++)
    //     {
    //         cin>>v[a][b];
    //     }
    // }
    // display(v);
    // for(auto i:v)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;
    vector<vector<int>> board;
    int i, j;cin>>i;cin>>j;
    vector<vector<int>> board(i);
    for(int a=0;a<i;a++)
    {
        for(int b=0;b<j;b++)
        {
            int s;
            cin>>s;
            board[i].push_back(s);
        }
    }
    // sudoku_solver(board, 0, 0);
    display(board);
}