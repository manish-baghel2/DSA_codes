#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<int>> board, int i, int j, int val)
{
    for(int x=0;x<board[0].size();x++)
    {
        if(board[i][x] == val)
        {
            return false;
        }
    }
    for(int y = 0;y<board.size();y++)
    {
        if(board[y][j]==val)
        {
            return false;
        }
    }

    int smi = i/3*3;
    int smj = j/3*3;
    for(int a=0;a<3;a++)
    {
        for(int b = 0;b<3;b++)
        {
            if(board[smi+a][smj+b] == val)
            {
                return false;
            }
        }
    }
    return true;
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

void sudoku_solver(vector<vector<int>> board, int i, int j)
{
    if( i == board.size())
    {
        display(board);
        return;
    }
    int ni=0,nj=0;
    if(j == board[0].size()-1)
    {
        ni=i+1;
    }else{
        ni = i;
        nj = j+1;
    }
    if(board[i][j] != 0)
    {
        sudoku_solver(board, ni, nj);
    }else
    {
        for(int t=1;t<=9;t++)
        {
            if(isvalid(board, i, j, t) == true)
            {
                board[i][j] = t;
                sudoku_solver(board, ni, nj);
                board[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> board = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    sudoku_solver(board, 0, 0);
}