#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      int n = heights.size();
      int m = heights[0].size();
      if (n == 1 && m == 1) return 0; // no effort

      vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); // effort array
      vector<vector<bool>> visited(n, vector<bool>(m, false)); // visited array

      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;

      min_heap.push({0, 0, 0}); // {effort, x, y}
      dist[0][0] = 0;

      int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
      
      while (!min_heap.empty()) {
        vector<int> node = min_heap.top();
        min_heap.pop();
        int eff = node[0];
        int x = node[1], y = node[2];

        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (x == n - 1 && y == m - 1) return eff; // early termination

        for (auto [drow, dcol] : directions) {
          int nrow = drow + x;
          int ncol = dcol + y;

          if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
            int newheight = max(abs(heights[nrow][ncol] - heights[x][y]), eff);

            dist[nrow][ncol] = min(dist[nrow][ncol], newheight);
            min_heap.push({dist[nrow][ncol], nrow, ncol});
          }
        }
      }

      return (dist[n-1][m-1] != INT_MAX) ? dist[n-1][m-1] : -1;
    }
};