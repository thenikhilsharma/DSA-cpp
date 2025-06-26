class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int iniColor) {
      ans[row][col] = newColor;
      int n = image.size();
      int m = image[0].size();
      for (int i=0; i<4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
          dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
        }
      }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
      int iniColor = image[sr][sc];
      if (iniColor == newColor) return image;
      vector<vector<int>> ans = image; // copying image
      int delRow[] = {-1, 0, +1, 0};
      int delCol[] = {0, +1, 0, -1};
      dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
      return ans;
    }
};

// adjacency matrix sol
class Solution {
private:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
                if (isConnected[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                bfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};