#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<int> &arr, int n) {
      // code here
    }
};

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

    if (arr[0] == 1) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}

/*
6
3
1 2 3
5
1 3 2 5 4
5
5 4 3 2 1
3
3 1 2
4
2 3 1 4
5
5 1 2 3 4

*/