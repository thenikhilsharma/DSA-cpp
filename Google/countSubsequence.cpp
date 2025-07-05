#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

class Solution {
  public:
    void solve(vector<int> &nums, int n, int idx, vector<int> &temp, long long &ans) {
      if (idx == n) {
        if (!temp.empty()) ans++;
        return;
      }
      // check the last element (odd/ even)
      // push an element
      // recursive call
      // pop that element
      // recursive call for not taking that element

      solve(nums, n, idx+1, temp, ans); // dont take element

      if (temp.empty() || 
        (nums[idx] % 2 != 0 && temp.back() % 2 == 0) || 
        (nums[idx] % 2 == 0 && temp.back() % 2 != 0)) {
        temp.push_back(nums[idx]);
        solve(nums, n, idx+1, temp, ans);
        temp.pop_back();
      }
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++) cin >> nums[i];
    Solution sol;
    long long ans = 0;
    vector<int> temp;
    sol.solve(nums, n, 0, temp, ans);
    cout << (ans % MOD) << endl;
  }

  return 0;
}
// tc
/*
1
4
1 2 3 5
*/