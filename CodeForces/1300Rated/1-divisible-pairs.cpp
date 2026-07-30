#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    
    // for (int i=0; i<n; i++) cin >> arr[i];
    // int ans = 0;
    // for (int i=0; i<n-1; i++) {
    //   for (int j=i+1; j<n; j++) {
    //     if ((arr[i] + arr[j]) % x == 0 && (arr[i] - arr[j]) % y == 0) ans++;
    //   }
    // }
    // cout << ans << endl;

    map<int, vector<int>> mpp;
    for (int i=0; i<n; i++) {
      cin >> arr[i];
      mpp[arr[i] % y].push_back(arr[i]);
    }

    long long int ans = 0;
    for (auto it: mpp) {
      vector<int> v = it.second;
      map<int, long long int> mpp1;
      for (int i=0; i<v.size(); i++) {
        mpp1[v[i]%x]++;
      }

      for (auto it: mpp1) {
        if (it.first == 0 || (it.first == x/2 && x%2 == 0)) {
          long long int cnt = it.second;
          ans += (cnt * (cnt - 1)) / 2;
          it.second = 0;
        } else {
          long long int cnt1 = it.second;
          long long int cnt2 = mpp1[x - it.first];
          ans += cnt1 * cnt2; // pairs from different remainders
          mpp1[x - it.first] = 0; // avoid double counting
        }
      }
    }

    cout << ans << endl;
  }
}