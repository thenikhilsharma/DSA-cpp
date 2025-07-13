#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int idx = 0){
  if (idx == static_cast<int>(arr.size())) return;
  int min_index = min_element(arr.begin() + idx, arr.end()) - arr.begin();
  swap(arr[idx], arr[min_index]);
  selectionSort(arr, idx+1);
}

int main() {

  vector<int> arr = {13, 46, 24, 52, 20, 9};
  selectionSort(arr);
  for (auto i: arr) cout << i << " ";
  cout << endl;

  return 0;
}