// leetcode q198

// recursion
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = subseq(nums, nums.size()-1);
        return ans;
    }

    int subseq(vector<int> &nums, int n){
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        int inc = subseq(nums, n-2) + nums[n];
        int exc = subseq(nums, n-1) + 0;
        
        return max(inc, exc);
    }
};

// recursion + memoization
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return subseq(nums, nums.size()-1, dp);
    }

    int subseq(vector<int> &nums, int n, vector<int> &dp){
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        if(dp[n] != -1) return dp[n];

        int inc = subseq(nums, n-2, dp) + nums[n];
        int exc = subseq(nums, n-1, dp) + 0;
        
        return dp[n] = max(inc, exc);
    }
};

// tabulation
class Solution {
public:
    int rob(vector<int>& nums){
        return subseq(nums);
    }

    int subseq(vector<int> &nums){
      int n = nums.size();
      vector<int> dp(n, 0);

      for(int i=0; i<n; i++){
        int inc = dp[i-2] + nums[i];
        int exc = dp[i-1];
        dp[i] = max(inc, exc);
      }
      return dp[n-1];
    }
};

// tabulation + space optimisation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];               // dp[i-2]
        int prev1 = max(nums[0], nums[1]);  // dp[i-1]

        for (int i = 2; i < n; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};