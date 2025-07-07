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
    if (n % 3 == 0) cout << "Second\n";
    else cout << "First\n";
  }

  return 0;
}

/*
6
1
3
5
100
999
1000

6
1 first (0 2)
3 second (2, 4)
5 first (6, 4)
100 (99)
999 second
1000 999

*/