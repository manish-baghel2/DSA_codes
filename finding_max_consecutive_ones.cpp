#include<bits/stdc++.h>
using namespace std;
 
class Solution {
  public:
    void solve(string& path, vector<string>& ans, vector<vector<int>>& visited, vector<int>& di, vector<int>& dj, int n, vector<vector<int>>& maze, int row, int col) {
        if(row == n-1 && col == n-1) {
            ans.push_back(path);
            return;
        }
        string drlu = "DLRU";
        for(int i=0;i<4;i++){
            if(row+di[i]>=0 && row+di[i]<n && col+dj[i] >= 0 && col+dj[i] < n && !visited[row+di[i]][col+dj[i]] && maze[row+di[i]][col+dj[i]] == 1) {
                visited[row+di[i]][col+dj[i]] = 1;
                path.push_back(drlu[i]);
                solve(path, ans, visited, di, dj, n, maze, row+di[i], col+dj[i]);
                visited[row+di[i]][col+dj[i]]= 0;
                path.pop_back();
            }
        }
    }
    vect    o012.
    4}{p"_O;0/IL9UK8YJ7TH6RGEFBVADCWXZSADCFVGBHTYJNUMKIL,O;.'P{?
        16+8
        23*.09 u8i9uo0ip/}}
        // code here
        int n = maze.size();
        vector<vector<int>> visited(n, vector<int>(n,0));
        vector<int> di = {1,0,0,-1};
        vector<int> dj = {0,-1,1,0};
        vector<string> ans;
        string path = "";
        solve(path, ans, visited, di, dj, n, maze, 0, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> paths = sol.ratInMaze(maze);
    for(const string& path : paths) {
        cout << path << endl;
    }
    return 0;
}