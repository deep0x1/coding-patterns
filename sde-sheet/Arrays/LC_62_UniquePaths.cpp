/**
 *
 * Source:    LeetCode
 * Problem:   62. Unique Paths
 *
 * Link:
 * https://leetcode.com/problems/unique-paths/description/
 *
 *
 * Time: O(M x N)
 * Space: O(M x N)
 *
 *
 * Approach:
 * we are back tracking the path from bottom to top while using DP to store the
 * possible unique paths form each index which is addition of both down and
 * right tile
 *
 */

#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n) {
  vector<vector<int>> matrix(m, vector<int>(n, 0));
  int row = m - 1;
  int col = n - 1;
  matrix[row][col] = 1;

  for (int i = row; i >= 0; i--) {
    for (int j = col; j >= 0; j--) {
      if (i == row && j == col) continue;

      // if not last row: Move Down
      if (i < row) {
        matrix[i][j] += matrix[i + 1][j];
      }

      // if not last col: Move Right
      if (j < col) {
        matrix[i][j] += matrix[i][j + 1];
      }
    }
  }

  return matrix[0][0];
}

int main() {
  int m = 3;
  int n = 7;
  cout << uniquePaths(m, n);
  return 0;
}