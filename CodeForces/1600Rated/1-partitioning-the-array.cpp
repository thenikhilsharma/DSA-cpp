// https://www.youtube.com/watch?v=M1vbWU9O3Eg

#include <bits/stdc++.h>
using namespace std;

vector<int> divisor(int n) {
  vector<int> div;
  for (int i=1; i*i<=n; i++) {
    if (n%i) continue;
    div.push_back(i);
    if (n/i != i) div.push_back(n/i);
  }
  return div;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(auto &x: a) cin >> x;
    vector<int> div = divisor(n);
    int ans = 0;
    for(auto &k : div) {
      int m = 0;
      for (int i=0; i<k; i++) {
        int base = a[i];
        for (int j=i+k; j<n; j+=k) {
          m = std::gcd(m, abs(a[j] - base));
        }
      }
      if (m != 1) ans++;
    }
    cout<<ans<<endl;
  }
}