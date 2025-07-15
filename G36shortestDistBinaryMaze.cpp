class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        if (n == 1) return 1;

        queue<pair<int, int>> q; // {x, y}
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        q.push({0, 0});
        dist[0][0] = 1;

        int dirs[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n-1 && y == n-1) return dist[x][y]; // if dist is reached early termination

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return -1; // Destination not reachable
    }
};