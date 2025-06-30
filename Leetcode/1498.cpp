// 1498. Number of Subsequences That Satisfy the Given Sum Condition

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recur(vector<int> &nums, int target, vector<int> &temp, int &ans, int i) {
        if (i >= nums.size()) return;
        if (temp.size() == 0) return;
        if (temp.size() == 1 && temp[0]*2 <= target) ans++;

        int maxi = *max_element(temp.begin(), temp.end());
        int mini = *min_element(temp.begin(), temp.end());
        if (mini + maxi < target) ans++;

        temp.push_back(nums[i]);
        recur(nums, target, temp, ans, i+1);
        temp.pop_back();
    }
    int numSubseq(vector<int>& nums, int target) {
        // brute force
        // find all subsequence - find the sum - if satisfy ans++
        int ans = 0;
        vector<int> temp;
        recur(nums, target, temp, ans, 0);
        return ans;
    }
};

int main() {
  vector<int> nums = {3, 5, 6, 7};
  int target = 9;
  Solution sol;
  cout << sol.numSubseq(nums, target);
}