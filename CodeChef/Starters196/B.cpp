#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n, int c) {
  sort(arr.begin(), arr.end());
  int ans = 0;
  if (*min_element(arr.begin(), arr.end()) > c) {
    ans = *min_element(arr.begin(), arr.end()) - c;
    c = *min_element(arr.begin(), arr.end());
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == c) {
      c++;
      ans++;
    }
  }
  return ans;
}

int main() {
	// 3 5
	// search if ai == c if exist increment c by 1 and check again
	// if not exist then check if any i > 0;

  int t;
  cin >> t;
  while(t--) {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = solve(arr, n, c);
    cout << ans << endl;
  }
}