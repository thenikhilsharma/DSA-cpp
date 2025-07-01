// 51. N-Queens

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool solve(int row, int col, vector<string> &board) {
      return true;
    }
  public:
    vector<vector<string>> solveNQueens(int n) {
      vector<string> emboard;
      for (int i=0; i<n; i++) {
        string s('.', n);
        emboard.push_back(s);
      }
    }
    vector<vector<string>> res;
    vector<string> board = emboard;
    if (solve(0, 0, board)) {
      res.push_back(board);
      board = emboard;
    }
    return res;
};

int main() {
  int n = 4;
  Solution sol;
  vector<vector<string>> res = sol.solveNQueens(n);
  for (auto i: res) {
    for (auto j: i) cout << j << endl;
    cout << endl;
  }
}