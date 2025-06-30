// 120. Triangle

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// top down - memoization
// class Solution {
// private:
//   int ans(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
//     if (row == triangle.size() - 1) return triangle[row][col];

//     if (dp[row][col] != -1) return dp[row][col];

//     int low = ans(row + 1, col, triangle, dp);
//     int lowr = ans(row + 1, col + 1, triangle, dp);
//     return dp[row][col] = triangle[row][col] + min(low, lowr);
//   }

// public:
//   int minimumTotal(vector<vector<int>> &triangle) {
//     int n = triangle.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));
//     return ans(0, 0, triangle, dp);
//   }
// };

// bottom up - tabulation
class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<int> dp(triangle.back());
    for (int row=n-2; row>=0; row--) {
      for (int col=0; col<=row; col++) {
        dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
      }
    }
    return dp[0];
  }
};

int main() {
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  Solution sol;
  cout << sol.minimumTotal(triangle);
}