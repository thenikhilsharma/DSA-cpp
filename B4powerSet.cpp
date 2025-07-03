// TC = O(n*2^n)
// SC ~ O(n*2^n)

#include<bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)

vector<vector<int>> sol(vector<int> nums) {
  int n = nums.size();
  int subsets = 1 << n; // 2^n
  vector<vector<int>> ans;
  for (int num=0; num<subsets; num++) {
    vector<int> temp;
    for (int i=0; i<n; i++) {
      if(num & (1 << i)) temp.push_back(nums[i]);
    }
    ans.push_back(temp);
  }
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 4};
  vector<vector<int>> res = sol(nums);
  for (auto i: res) {
    cout << "{ ";
    for (auto j:i) cout << j << " ";
    cout << "}" << endl;
  }
}