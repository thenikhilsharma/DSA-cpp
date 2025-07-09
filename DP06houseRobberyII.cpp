// 213. House Robber II

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 0) return 0;
        vector<int> num1, num2;
        for(int i=0; i<nums.size(); i++){
            if (i != 0) num1.push_back(nums[i]);
            if (i != nums.size() - 1) num2.push_back(nums[i]);
        }
        int a = sol(num1);
        int b = sol(num2);
        return max(a, b);
    }
    int sol(vector<int> nums){
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