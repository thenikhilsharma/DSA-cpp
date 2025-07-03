#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC = (Nlog(N) + N/3)
// SC = O(1)
int sol(vector<int> &nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  for (int i=1; i<n; i+=3) {
    if (nums[i] != nums[i-1]) return nums[i-1];
  }
  return nums[n-1];
}

// TC = O(N)
// SC = O(1)
int sol2(vector<int> &nums) {
  int n = nums.size();
  int ones = 0, twos = 0;
  for (int i=0; i<n; i++) {
    ones = (ones ^ nums[i]) & ~twos;
    twos = (twos ^ nums[i]) & ~ones;
  }
  return ones;
}

// TC = O(N*32)
// SC = O(1)
int main() {
  vector<int> nums = {5, 5, 5, 2, 4, 4, 4};
  int n = nums.size();
  int ans = 0;
  for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
      if (nums[i] & (1 << bitIndex)) cnt++; // checking ith bit in the no.
    }
    if (cnt % 3 == 1) ans = ans | (1 << bitIndex); // setting ith bit in the no.
  }
  cout << ans << endl;
  // optimised code
  cout << sol2(nums);
}
