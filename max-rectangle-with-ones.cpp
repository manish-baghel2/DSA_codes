#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargest(vector<int>& v, int m) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(m);
    for(int i = m-1; i>=0; i--) {
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr) s.pop();
        ans[i] = (s.top());
        s.push(i);
    }
    return ans;
}

vector<int> prevLargest(vector<int>& v, int m) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(m);
    for(int i = 0; i < m; i++) {
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr) s.pop();
        ans[i] = (s.top());
        s.push(i);
    }
    return ans;
}


int largestHistogram(vector<int>& v, int m) {
    vector<int> next(m);
    vector<int> prev(m);
    next = nextLargest(v, m);
    prev = prevLargest(v,m);
    int area = 0;
    for(int i = 0 ; i < m; i++) {
        if(next[i] == -1) next[i] = m;
        int l = v[i];
        int b = next[i] - prev[i] - 1;
        int currArea = l * b;
        area = max(area, currArea);
    }
    return area;
}

int maxRectangle(vector<vector<int>>& M, int n, int m) {
    int area = largestHistogram(M[0],m);
    for(int i = 1; i < n; i++) {
        for(int j = 0 ; j< m ; j++) {
            if(M[i][j] != 0) {
                M[i][j] += M[i-1][j];
            }
        }
        int currArea = largestHistogram(M[i],m);
        area = max(area, currArea);
    }
    return area;
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 0, 0, 1}
    };
    int n = M.size();
    int m = M[0].size();
    cout << "Maximum rectangle with all 1s is: " << maxRectangle(M, n, m) << endl;
    return 0;
}