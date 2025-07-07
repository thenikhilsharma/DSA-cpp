#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];

    map<long long, long long> mpp;
    for (int i=0; i<n; i++) mpp[arr[i]]++;

    if (mpp.size() >= 3) cout << "No\n";
    else {
      long long freq1 = mpp.begin()->second;
      long long freq2 = mpp.rbegin()->second;
      if (freq1 == freq2) cout << "Yes\n";
      else if (n % 2 == 1 && abs(freq1 - freq2) == 1) cout << "Yes\n";
      else cout << "No\n";
    }
  }

  return 0;
}

/*
5
2
8 9
3
1 1 2
4
1 1 4 5
5
2 3 3 3 3
4
100000 100000 100000 100000

*/