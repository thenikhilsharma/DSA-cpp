// 931. Minimum falling path sum

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// recursive - memoization
// class Solution
// {
// private:
//   int path(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
//     if (row >= matrix.size() || col >= matrix.size() || col < 0 || row < 0) return INT_MAX; // out of bound
//     if (row == matrix.size() - 1) return matrix[row][col]; // base case
//     if (dp[row][col] != -1) return dp[row][col]; // dp memoization

//     int down = path(row + 1, col, matrix, dp);
//     int downL = path(row + 1, col - 1, matrix, dp);
//     int downR = path(row + 1, col + 1, matrix, dp);
//     return dp[row][col] = matrix[row][col] + min({down, downL, downR});
//   }

// public:
//   int minFallingPathSum(vector<vector<int>> &matrix) {
//     int n = matrix.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     int minSum = INT_MAX;
//     for (int col = 0; col < n; ++col)
//     {
//       minSum = min(minSum, path(0, col, matrix, dp));
//     }
//     return minSum;
//   }
// };

// bottom up tabulation
class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0]; // edge case
        
    vector<int> prev = matrix[0];
    vector<int> curr(n);

    for (int row = 1; row < n; row++) {
      for (int col = 0; col < n; col++) {
        int minPrev = prev[col];
        if (col > 0) minPrev = min(minPrev, prev[col-1]);
        if (col < n-1) minPrev = min(minPrev, prev[col+1]);
        curr[col] = matrix[row][col] + minPrev;
      }
      swap(prev, curr);
    }
    return *min_element(prev.begin(), prev.end());
  }
};

int main()
{
  vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  Solution sol;
  cout << sol.minFallingPathSum(matrix);
}