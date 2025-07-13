#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int target) { // arr[index] > n
  int ans = arr.size() - 1;
  int low = 0, high = arr.size()-1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] > target) {
      ans = mid;
      high = mid-1;
    }
    else low = mid+1;
  }
  return ans; // returns index
}

int main() {
  vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
  auto it = upper_bound(arr.begin(), arr.end(), 5); // direct
  cout << upperBound(arr, 5) << " " << *it << " " << it - arr.begin();
}