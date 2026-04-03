/**
 *
 * Source:    LC
 * Problem:   51. N-Queens
 *
 *
 * Link:
 * https://leetcode.com/problems/n-queens/description/
 *
 *
 * Time: O(N!)
 * Space: O(N)
 *
 *
 * Approach:
 * recursivling putting 1 queen on each row and checking above
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool check(int row, int col, vector<string>& curr) {
  int n = curr.size();
  int i, left, right;

  // check col
  for (i = row - 1; i >= 0; i--) {
    if (curr[i][col] == 'Q') {
      return false;
    }
  }

  // check left diagonal
  i = row - 1;
  left = col - 1;
  right = col + 1;
  while (i >= 0) {
    if (left >= 0) {
      if (curr[i][left] == 'Q') return false;
    }
    if (right < n) {
      if (curr[i][right] == 'Q') return false;
    }

    i--;
    left--;
    right++;
  }

  return true;
}

void solve(int row, vector<string>& curr, vector<vector<string>>& grid) {
  int n = curr.size();
  if (row == n) {
    grid.push_back(curr);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (check(row, i, curr)) {
      curr[row][i] = 'Q';
      solve(row + 1, curr, grid);
      curr[row][i] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> grid;
  vector<string> curr(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      curr[i].push_back('.');
    }
  }
  solve(0, curr, grid);
  return grid;
}

int main() {
  int n = 4;
  vector<vector<string>> result = solveNQueens(n);
  for (auto row : result) {
    for (auto col : row) {
      cout << col << endl;
    }
    cout << endl;
  }
  return 0;
}