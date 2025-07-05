#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// we have to sort boxes in ascending order
// but only k subarray reversal are allowed

class Solution {
  public:
    bool solve(vector<int> &arr, int n) {
      vector<int> copy = arr;
      sort(copy.begin(), copy.end());

      // check if array is already sorted
      int len = 0;
      for (int i=0; i<n; i++) {
        if (arr[i] == copy[i]) len++;
        else break;
      }
      if (len == n) return true;

      // check if array has all duplicate elements
      len = 0;
      for (int i=1; i<n; i++) {
        if (arr[i] == arr[i-1]) len++;
        else break;
      }
      if (len == n-1) return true;

      return false;
    }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    if (k == 1) {
      Solution sol;
      if (sol.solve(arr, n)) cout << "YES\n";
      else cout << "NO\n";
    }
    else cout << "YES\n";
  }

  return 0;
}
/*
5
3 2
1 2 3
3 1
9 9 9
4 4
6 4 2 1
4 3
10 3 830 14
2 1
3 1

*/