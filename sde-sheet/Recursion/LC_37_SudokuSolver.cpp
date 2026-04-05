/**
 *
 * Source:    LC
 * Problem:   37. Sudoku Solver
 *
 *
 * Link:
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 *
 * Time: O(9^N)
 * Space: O(9^N)
 *
 *
 * Approach:
 * using recursion to try all possible solutoins by putting 1 - 9 one by one and
 * validating, if validation fails then that branch is dead and we return back
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == c) return false;
    if (board[i][col] == c) return false;

    int boxRow = 3 * (row / 3) + i / 3;
    int boxCol = 3 * (col / 3) + i % 3;
    if (board[boxRow][boxCol] == c) return false;
  }
  return true;
}

bool solve(vector<vector<char>>& board) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, row, col, c)) {
            board[row][col] = c;
            if (solve(board)) return true;
            board[row][col] = '.';
          }
        }
        return false;
      }
    }
  }
  return true;
}

void solveSudoku(vector<vector<char>>& board) { solve(board); }

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  solveSudoku(board);
  for (auto row : board) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << endl;
  }
  return 0;
}