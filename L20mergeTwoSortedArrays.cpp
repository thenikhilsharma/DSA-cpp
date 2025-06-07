#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &arr1, vector<int> &arr2){
  int idx = 0, jdx = 0;
  vector<int> arr3;
  while (idx < arr1.size() && jdx < arr2.size()){
    if (arr1[idx] <= arr2[jdx]){
      arr3.push_back(arr1[idx]);
      idx++;
    }
    else{
      arr3.push_back(arr2[jdx]);
      jdx++;
    }
  }
  while (idx < arr1.size()){
    arr3.push_back(arr1[idx]);
    idx++;
  }
  while (jdx < arr2.size()){
    arr3.push_back(arr2[jdx]);
    jdx++;
  }
  return arr3;
}

void print(vector<int> &arr){
  for (auto i:arr){
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  vector<int> arr1 = {1, 4, 5, 6};
  vector<int> arr2 = {2, 3};
  vector<int> arr3 = merge(arr1, arr2);
  print(arr3);
}