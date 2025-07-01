/* B. Tournament

You are given an array of integers a1,a2,…,an
A tournament is held with n players. Player i has strength ai

While more than k players remain,

Two remaining players are chosen at random;
Then the chosen player with the lower strength is eliminated. If the chosen players have the same strength, one is eliminated at random.
Given integers j and k (1≤j,k≤n), determine if there is any way for player j to be one of the last k remaining players. */

#include<iostream>
#include<vector>
using namespace std; 

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    // solve
    string s = (k>1 || *max_element(a.begin(), a.end()) == a[j-1]) ? "YES" : "NO";
    cout << s << endl;
  }
}