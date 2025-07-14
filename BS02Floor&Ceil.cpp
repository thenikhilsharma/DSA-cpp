// floor = largest no in array <= target
// ceil = smallest no in array >= target

#include <bits/stdc++.h>
using namespace std;

int Floor(vector<int> &arr, int target) {
  int ans = -1;
  int low = 0, high = arr.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= target) {
      ans = arr[mid];
      low = mid + 1;
    } else high = mid - 1;
  }
  return ans;
}

int Ceil(vector<int> &arr, int target) {
  int ans = -1;
  int low = 0, high = arr.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= target) {
      ans = arr[mid];
      high = mid - 1;
    } else low = mid + 1;
  }
  return ans;
}

int main() {
  vector<int> arr = {10, 20, 30, 40};
  cout << Floor(arr, 25) << endl << Ceil(arr, 25);
}