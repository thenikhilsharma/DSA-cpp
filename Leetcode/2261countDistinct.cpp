#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        // brute force
        // find all subarrays, check if divisible by p, and store in set
        set<vector<int>> distinctSubarrays;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            vector<int> currentSubarray;
            int count = 0;
            for (int j = i; j < n; ++j) {
                currentSubarray.push_back(nums[j]);
                if (nums[j] % p == 0) {
                    count++;
                }
                if (count > k) {
                    break; // stop if we exceed k divisible elements
                }
                distinctSubarrays.insert(currentSubarray);
            }
        }

        return distinctSubarrays.size();

        // optimized approach
        unordered_set<size_t> distinctHashes;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            size_t rollingHash = 0;
            
            for (int j = i; j < n; ++j) {
                if (nums[j] % p == 0) {
                    count++;
                }
                if (count > k) {
                    break;
                }
                
                // Compute rolling hash for the current subarray
                rollingHash = rollingHash * 257 + nums[j] + 1;
                distinctHashes.insert(rollingHash);
            }
        }
        
        return distinctHashes.size();
    }
};