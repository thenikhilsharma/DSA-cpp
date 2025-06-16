//3584. Maximum Product of First and Last Elements of a Subsequence

class Solution {
public:
    // brute force - generate all subsequence of size m -> product temp[0] * temp[temp.size()-1] -> ans = max(ans, product)
    long long maximumProduct(vector<int>& nums, int m) {
        vector<int> temp;
        vector<int> dp(nums.size()+1);
        long long ans = LLONG_MIN;
        subseq(nums, m, 0, temp, ans);
        return ans;
    }

    void subseq(vector<int>& nums, int m, int i, vector<int> &temp, long long &ans){
        if (i >= nums.size()) return;

        if (dp[i].count()) return dp[i];
        temp.push_back(nums[i]);
        int n = temp.size();
        if (n == m) {
            long long prod = (long long)temp[0] * temp.back();
            ans = max(ans, prod);
        } else subseq(nums, m, i + 1, temp, ans); // recurse further if size < m
        temp.pop_back();
        subseq(nums, m, i + 1, temp, ans);
    }
};