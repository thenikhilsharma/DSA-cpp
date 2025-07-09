// 931. Minimum Falling Path Sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];

        vector<int> prev = matrix[0];
        vector<int> curr(n);

        for (int i=1; i<n; i++) {
            for (int j=0; j<n; j++) {
                int minSum = prev[j];
                if (j+1 < n) minSum = min(minSum, prev[j+1]);
                if (j-1 >= 0) minSum = min(minSum, prev[j-1]);
                curr[j] = matrix[i][j] + minSum;
            }
            swap(prev, curr);
        }
        return *min_element(prev.begin(), prev.end());
    }
};