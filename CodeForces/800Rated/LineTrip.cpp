#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int> &arr, int x) {
      int res = 0, ans = 0;
      for (int i=1; i<=x; i++) {
        res--;
        if (find(arr.begin(), arr.end(), i) != arr.end()) {
          ans = min(ans, res);
          res = 0;
        }
      }

      // do reverse
      for (int i=x-1; i>=1; i--) {
        res--;
        if (find(arr.begin(), arr.end(), i) != arr.end()) {
          ans = min(ans, res);
          res = 0;
        }
      }
      return abs(ans);
    }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    Solution sol;
    cout << sol.solve(arr, x) << endl;
  }

  return 0;
}
// 0 (-1 0) (-1 0) (-1 -1) (-2 -2) (-3 0) (-1 -1) (-2 -2) (-3 -3) (-4 0)
// 0 (-1 0) (-1 0) (-1 -1) (-2 -2) (-3 0) (-1 -1) (-2 -2) (-3 0)
// 0 -1 -1 -2 -2 -3 -3 -4 -4 -5 -5 -6 -6 -7 0 -1 -1 -2 -2 -3 -3 -4 -4 -5 -5 -6 0
// iterate from 1 to x;
// keep on subtracting res at every i
// if gas station is there update ans = min(ans, res)
// and res = 0
// do for reverse too x to 1
// ans = abs(ans)
/*
3
3 7
1 2 5
3 6
1 2 5
1 10
7

*/