// 64. Minimum Path Sum

class Solution {
private:
    int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        int n = grid.size(), m = grid[0].size();
        if (row >= n || col >= m) return INT_MAX;
        if (row == n - 1 && col == m-1) return grid[row][col];
        if (dp[row][col] != -1) return dp[row][col];
        
        int down = dfs(row+1, col, grid, dp);
        int right = dfs(row, col+1, grid, dp);

        return dp[row][col] = grid[row][col] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(0, 0, grid, dp);
    }
};