// https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pre(m+1, vector<int>(n+1, 0));
        for (int i=1; i<=m; i++)
            for (int j=1; j<=n; j++)
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];

        auto allOnes = [&](int r, int c, int k) -> bool {
            int sum = pre[r+k][c+k] - pre[r][c+k] - pre[r+k][c] + pre[r][c];
            return sum == k * k;
        };

        int lim = min(m, n);
        for (int k=lim; k>=1; k--) {
            int minR = INT_MAX, maxR = INT_MIN, minC = INT_MAX, maxC = INT_MIN;
            bool found = false;

            for (int r=0; r+k<=m; r++) {
                for (int c=0; c+k<=n; c++) {
                    if (allOnes(r, c, k)) {
                        found = true;
                        minR= min(minR, r);
                        maxR = max(maxR, r);
                        minC = min(minC, c);
                        maxC = max(maxC, c);
                    }
                }
            }

            if (found && (maxR - minR >= k || maxC - minC >= k)) return k*k;
        }

        return 0;
    }
};