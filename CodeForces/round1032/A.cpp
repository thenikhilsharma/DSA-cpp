// A. Letter Home
// a = {1, 2, 3, 9, 10, 11}
// s = 6
// (s- a[0])*2 + (a[n-1] - s)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void f(const vector<int>& a, int n, int s) {
      if (n == 0) cout << 0 << endl;
      int ans = 0;
      if (s <= a[0]) ans = a[n-1] - s;
      else if (s >= a[n-1]) ans = s - a[0];
      else ans = (a[n-1] - a[0] + min(s-a[0], a[n-1]-s));
      cout << ans << endl;
      return;
    }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
      cin >> arr[i];
    }

    Solution sol;
    sol.f(arr, n, s);
  }
}