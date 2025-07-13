#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int idx = 0){ // O(n^2), use when array size is small
  if (idx == static_cast<int>(arr.size())) return;
  int min_index = min_element(arr.begin() + idx, arr.end()) - arr.begin();
  swap(arr[idx], arr[min_index]);
  selectionSort(arr, idx+1);
}

int main() {

  vector<int> arr = {29, 72, 98, 13, 87, 66, 52, 51, 36};
  selectionSort(arr);
  for (auto i : arr) cout << i << " ";
  cout << endl;

  return 0;
}