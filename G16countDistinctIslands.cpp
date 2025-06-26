// do dfs -  store the island in a set<list> - set.size() = ans

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &vec, int row0, int col0) {
      int n = grid.size();
      int m = grid[0].size();
      
      vis[row][col] = true;
      vec.push_back({row - row0, col - col0});

      int delrow[4] = {-1, 0, +1, 0};
      int delcol[4] = {0, -1, 0, +1};
      for (int x=0; x<4; x++) {
        int nrow = row + delrow[x];
        int ncol = col + delcol[x];
        if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1) dfs(nrow, ncol, grid, vis, vec, row0, col0);
      }
    }
  public:
    int countDistinctIslands(vector<vector<int>> &grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<bool>> vis(n, vector<bool>(m, false));
      set<vector<pair<int, int>>> st;
      for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
          vector<pair<int, int>> vec;
          if (!vis[i][j] && grid[i][j]) {
            dfs(i, j, grid, vis, vec, i, j);
            st.insert(vec);
          }
        }
      }

      return st.size();
    }
};

int main() {
  vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                              {1, 1, 0, 0, 0},
                              {0, 0, 0, 1, 1},
                              {0, 0, 0, 1, 1}};
  Solution sol;
  cout << sol.countDistinctIslands(grid);
}