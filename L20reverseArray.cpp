#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> &arr){
  int low = 0, high = arr.size()-1;
  while (low <= high){
    swap(arr[low], arr[high]);
    low++;
    high--;
  }
  return arr;
}

void print(vector<int> &arr){
  for (auto i:arr){
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  // int arr[5] = {1, 4, 2, 3, 5};
  vector<int> arr = {1, 4, 2, 3, 5};
  reverse(arr);
  print(arr);
}