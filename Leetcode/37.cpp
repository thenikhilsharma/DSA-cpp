// 37. Sudoku Solver

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool isValid(int row, int col, int element, vector<vector<char>> &board)
  {
    for (int i = 0; i < 9; i++)
    {
      if (board[row][i] == element)
        return false;
    }
    for (int i = 0; i < 9; i++)
    {
      if (board[i][col] == element)
        return false;
    }
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (board[boxStartRow + i][boxStartCol + j] == element)
        {
          return false;
        }
      }
    }
    return true;
  }

  bool solve(int row, int col, vector<vector<char>> &board)
  {
    // If we've reached the end, return true
    if (row == 9)
      return true;

    // If current cell is not empty, move to next
    if (board[row][col] != '.')
    {
      if (col == 8)
        return solve(row + 1, 0, board);
      else
        return solve(row, col + 1, board);
    }

    // Try all possible numbers
    for (char num = '1'; num <= '9'; num++)
    {
      if (isValid(row, col, num, board))
      {
        board[row][col] = num;

        // Move to next cell
        if (col == 8)
        {
          if (solve(row + 1, 0, board))
            return true;
        }
        else
        {
          if (solve(row, col + 1, board))
            return true;
        }

        // Backtrack
        board[row][col] = '.';
      }
    }
    return false;
  }

public:
  void solveSudoku(vector<vector<char>> &board)
  {
    solve(0, 0, board);
  }
};

int main()
{
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  Solution sol;
  sol.solveSudoku(board);
  for (auto i : board)
  {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
}