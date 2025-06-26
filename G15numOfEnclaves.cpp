// 1020. Number of Enclaves
// grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}}
// traverse boundary
// if 1 is found - apply dfs and mark them as 0 and visited
// count remaining not visited 1s

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
  void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
    vis[row][col] = true;
    int n = grid.size();
    int m = grid[0].size();

    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};

    for (int x=0; x<4; x++) {
      int nrow = row + drow[x];
      int ncol = col + dcol[x];

      if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) dfs(nrow, ncol, grid, vis);
    }
  }

public:
  int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    int count = 0;

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // iterating on the boundary
    for (int j=0; j<m; j++) {
      if (!vis[0][j] && grid[0][j] == 1) dfs(0, j, grid, vis); // top
      if (!vis[n-1][j] && grid[n-1][j] == 1) dfs(n-1, j, grid, vis); // bottom
    }
    for (int i=0; i<n; i++) {
      if (!vis[i][0] && grid[i][0] == 1) dfs(i, 0, grid, vis); // left
      if (!vis[i][m-1] && grid[i][m-1] == 1) dfs(i, m-1, grid, vis); // right
    }

    // counting remaining 1s
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (!vis[i][j] && grid[i][j] == 1) count += 1;
      }
    }

    return count;
  }
};

int main() {
  vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
  Solution sol;
  cout << "ans: " << sol.numEnclaves(grid) << endl;
  for (auto i: grid){
    for (auto j: i){
      cout << j << " ";
    }
    cout << endl;
  }
}