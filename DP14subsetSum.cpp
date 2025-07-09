#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// backtracking solution
class Solution1 {
private:
  bool sub(int idx, int currentSum, vector<int> &arr, int sum) {
    if (currentSum == sum) return true; // Subset found
    if (idx == static_cast<int>(arr.size())) return false; // Reached end without finding

    if (sub(idx + 1, currentSum + arr[idx], arr, sum)) return true; // include element
    return sub(idx + 1, currentSum, arr, sum); // exclude element
  }

public:
  bool isSubsetSum(vector<int> &arr, int sum) {
    return sub(0, 0, arr, sum);
  }
};

// memoization solution
class Solution2 {
public:
  bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(n-1, sum, arr, dp);
  }

private:
  bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) return true;
    if (ind == 0) return (arr[0] == target);
    if (dp[ind][target] != -1) return dp[ind][target];

    bool nottake = f(ind-1, target, arr, dp);
    bool take = false;
    if (target >= arr[ind]) take = f(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take || nottake;
  }
};

// tabulation - bottom up
class Solution3 {
  public:
    int isSubsetSum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
          
      // base cases
      for (int i = 0; i < n; i++) dp[i][0] = true; // empty subset
        dp[0][nums[0]] = true; // first element
          
        for (int ind = 1; ind < n; ind++) {
          for (int target = 1; target <= k; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (nums[ind] <= target) take = dp[ind - 1][target - nums[ind]];
              dp[ind][target] = take || notTake;
          }
        }
        return dp[n-1][k-1];
    }
};

// tabulation - bottom up (space optimisation)
class Solution4 {
public:
  bool isSubsetSum(vector<int> &arr, int sum) {
    int n = arr.size();
    vector<bool> prev(sum + 1, false), curr(sum + 1, false);
    prev[0] = true;
    if (arr[0] <= sum) prev[arr[0]] = true;    
    for (int i = 1; i < n; i++) {
      curr[0] = true;
      for (int j = 1; j <= sum; j++) {
        bool nottake = prev[j];
        bool take = false;
        if (j >= arr[i]) take = prev[j - arr[i]];
          curr[j] = take || nottake;
      }
      prev = curr;
    }
    return prev[sum];
  }
};

int main() {
  vector<int> arr = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  Solution4 sol;
  cout << sol.isSubsetSum(arr, sum);
}