/**
 *
 * Source:    LeetCode
 * Problem:   73. Set Matrix Zeroes
 * Link:      https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 *
 * Time: O(mn)
 * Space: O(1)
 * 
 * 
 * Approach:
 * loop though the whole array and use 0th row and col as flag
 * use col0 and row0 to capture the overlaping of 0th row and col
 *
 */

#include <bits/stdc++.h>

using namespace std;

void setZeros(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();

  int i, j;
  bool col0 = false;
  bool row0 = false;

  // phase 1: loop through matrix and flag 0s
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        if (i == 0) row0 = true;
        if (j == 0) col0 = true;
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  // phase 2: make rows and cols 0 based on flags
  for (i = 1; i < rows; i++) {
    for (j = 1; j < cols; j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  // phase 3: check edge case
  if (col0) {
    for (i = 0; i < rows; i++) {
      matrix[i][0] = 0;
    }
  }

  if (row0) {
    for (j = 0; j < cols; j++) {
      matrix[0][j] = 0;
    }
  }
}

int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeros(matrix);
  for (auto row : matrix) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "\n";
  }
  return 0;
}