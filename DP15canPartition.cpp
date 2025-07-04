// given an array check if we can partition 2 such array to have equal sum
// approach - calculate total sum
// divide the sum by 2
// find subset equal to sum/2
// the other subset is bound to have that sum else check again

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    if (totalSum % 2 != 0) return false;

    int targetSum = totalSum / 2;
    vector<bool> dp(targetSum + 1, false);
    dp[0] = true;
    for (int num : nums)
    {
      for (int currSum = targetSum; currSum >= num; --currSum)
      {
        dp[currSum] = dp[currSum] || dp[currSum - num];
        if (dp[targetSum]) return true;
      }
    }
    return dp[targetSum];
  }
};

int main()
{
  vector<int> nums = {2, 2, 3, 3, 4, 7};
  Solution sol;
  cout << sol.canPartition(nums);
}