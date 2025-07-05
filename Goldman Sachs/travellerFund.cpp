#include <bits/stdc++.h>
using namespace std;

bool calc_if_x_fits(const vector<long long> &arr, long long x) {
  for (auto end : arr) {
    x = x + end;
    if (x <= 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 0) {
      cout << 0;
      return 0;
    }
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long left = 0, right = 1e18;
    long long res = right;

    while (left <= right) {
      long long mid = left + (right - left) / 2;
      if (calc_if_x_fits(arr, mid)) {
        res = mid;
        right = mid - 1;
      }
      else left = mid + 1;
    }
    cout << res << endl;
  }
  return 0;
}