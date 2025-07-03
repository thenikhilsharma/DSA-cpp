// TC = O(N)
// SC = O(1)

#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> nums = {4, 1, 2, 1, 2};
  int n = nums.size();
  int XOR = 0;
  for (int i = 0; i < n; i++) {
    XOR = XOR ^ nums[i];
  }
  cout << XOR << endl;
}