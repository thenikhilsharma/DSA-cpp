// 198. House Robber
// maximum sum of non adjacent elements

class Solution {
public:
    int f (int idx, vector<int> &nums, vector<int> &dp) {
        if (idx == 0 || idx == 1) return nums[idx];
        if (idx < 0) return 0;

        if (dp[idx] != -1) return dp[idx];
        
        return dp[idx] = max(f(idx-2, nums, dp) + nums[idx], f(idx-1, nums, dp) + 0);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(nums.size()-1, nums, dp);
    }
};