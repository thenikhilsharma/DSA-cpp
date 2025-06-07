#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums){
  int nonZero = 0;
  for (int j=0; j<nums.size(); j++){
    if (nums[j] != 0){
      swap(nums[j], nums[nonZero]);
      nonZero++;
    }
  }
}

void print(vector<int> &nums){
  for (auto i:nums){
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  vector<int> nums = {0, 1, 0, 3, 12, 0};
  moveZeroes(nums);
  print(nums);
}