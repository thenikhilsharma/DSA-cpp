// 63. Unique Paths II

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return dfs(0, 0, m, n, dp, obstacleGrid);
    }

    int dfs(int x, int y, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if (x == m-1 && y == n-1) return 1;
        
        // out of bounds or obstacle
        if (x >= m || y >= n || obstacleGrid[x][y] == 1) return 0;
        
        // memoized result
        if (dp[x][y] != 0) return dp[x][y];

        dp[x][y] = dfs(x+1, y, m, n, dp, obstacleGrid) + 
                   dfs(x, y+1, m, n, dp, obstacleGrid);
        return dp[x][y];
    }
};