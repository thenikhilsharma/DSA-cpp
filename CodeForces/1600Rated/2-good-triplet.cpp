// https://www.youtube.com/watch?v=mYEodDLzM2k

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> split(10, 0);
  for (int i = 0; i <= 9; i++) {
    for (int j=0; j <= 9; j++) {
      for (int k=0; k<=9; k++) {
        if (i + j + k < 10) split[i+j+k]++;
      }
    }
  }

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    ll ans = 1;
    for (char x : s) {
      ans *= split[x-'0'];
    }
    cout << ans << endl;
  }
  return 0;
}