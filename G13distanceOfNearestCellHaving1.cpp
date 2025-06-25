// 0 0 0
// 0 1 0
// 1 0 1
// apply multi BFS for every 1

#include <vector>
#include<iostream>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<vector<int>> distance(vector<vector<int>> &grid) {
      int n = grid.size(); // rows
      int m = grid[0].size(); // columns
      vector<vector<int>> dist(n, vector<int>(m, -1));
      // vector<vector<int>> vis(n, vector<int>(m, 0)); // visited array
      // vis[n][m] = {0}; // other way to initialise visited array

      queue<pair<pair<int, int>, int>> q; // {row, col}, dist

      for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
          if (grid[i][j] == 1) {
            dist[i][j] = 0;
            q.push({{i, j}, 0});
          }
        }
      }
      
      int drow[4] = {-1, 0, +1, 0};
      int dcol[4] = {0, +1, 0, -1};

      while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
          int nrow = row + drow[i];
          int ncol = col + dcol[i];

          if (nrow<n && nrow>=0 && ncol<m && ncol>=0 && dist[nrow][ncol] == -1){
            dist[nrow][ncol] = d + 1;
            q.push({{nrow, ncol}, d + 1});
          }
        }
      }
      return dist;
    }
};

int main() {

  vector<vector<int>> grid = {{0, 0, 0},
                              {0, 1, 0},
                              {1, 0, 1}};
  Solution sol;
  vector<vector<int>> ans = sol.distance(grid);
  for (auto i: ans) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}