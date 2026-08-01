#include <bits/stdc++.h>
using namespace std;

bool initcheck(vector<int> &a) {
  int i=0, j=a.size()-1;
  while (i<j) {
    if (abs(a[i] - a[j]) > 2) return false;
    if (abs(a[i] - a[j]) == 1) return false;
    i++; j--;
  }
  return true;
}

vector<int> validx(vector<int> &a) {
  int i=0, j=a.size()-1;
  vector<int> valid;
  while (i<j) {
    int x = (a[i] + a[j])/2;
    if(count(a.begin(), a.end(), x) == 0) valid.push_back(x);
    i++; j--;
  }
  return valid;
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    bool ans = true;
    for (auto &ch : a) cin >> ch;
    if (!initcheck(a)) ans = false;
    vector<int> valid = validx(a);
    for (auto x: valid) {
      int i=0, j=n-1;
      while(i<j) {
        int m = a[i], n=a[j];
        m += (m <= x) ? 1 : -1;
        n += (n <= x) ? 1 : -1;
        if (m != n) break;
        i++; j--;
      }
      if (i!=j) ans = false;
      else ans = true;
    }

    if (ans) cout<<"YES\n";
    else cout<<"NO\n";
  }
  return 0;
}