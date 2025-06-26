// traverse boundary - if O is found apply dfs and mark all connecting O's as visited and do not change
// traverse remaining not visited O's and mark them as visited

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
  void dfs(int row, int col, vector<vector<char>> &board, vector<vector<bool>> &vis) {
    int n = board.size();
    int m = board[0].size();
    vis[row][col] = true;

    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};

    for (int x=0; x<4; x++) {
      int nrow = row + drow[x];
      int ncol = col + dcol[x];

      if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') dfs(nrow, ncol, board, vis);
    }
  }

public:
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // top and bottom
    for (int j=0; j<m; j++) {
      if (board[0][j] == 'O' && vis[0][j] == false) dfs(0, j, board, vis); // top
      if (board[n-1][j] == 'O' && vis[n-1][j] == false) dfs(n-1, j, board, vis); // bottom
    }
    // sides
    for (int i=0; i<n; i++) {
      if (board[i][0] == 'O' && vis[i][0] == false) dfs(i, 0, board, vis); // left side
      if (board[i][m-1] == 'O' && vis[i][m-1] == false) dfs(i, m-1, board, vis); // right side
    }

    // mark remaining not visited O's as X
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
      }
    }
  }
};

int main() {
  vector<vector<char>> board = {{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}};
  Solution sol;
  sol.solve(board);
  for (auto i: board){
    for (auto j: i){
      cout << j << " ";
    }
    cout << endl;
  }
}