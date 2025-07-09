// 62. Unique Paths

class Solution {
public:
    int uniquePaths(int m, int n) {
        map<pair<int, int>, bool> visited;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = dfs(m-1, n-1, 0, 0, visited, dp);
        return ans;
    }

    int dfs(int m, int n, int x, int y, map<pair<int, int>, bool>& visited, vector<vector<int>> &dp) {

        if (x == n && y == m) return 1; // reached the target
        if (x > n || y > m || x < 0 || y < 0) return 0; // out of bounds
        if (visited[{x, y}]) return 0; // already visited
        if (dp[x][y] != 0) return dp[x][y];

        visited[{x, y}] = true;
        dp[x][y] = dfs(m, n, x+1, y, visited, dp) + dfs(m, n, x, y+1, visited, dp);
        visited[{x, y}] = false;

        return dp[x][y];
    }
};