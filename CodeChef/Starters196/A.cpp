#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  string s = (b >= a*3) ? "Rain" : "Dry";
  cout << s << endl;

  return 0;
}