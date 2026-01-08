/**
 *
 * Source:    LeetCode
 * Problem:   48. Rotate Image
 * Link:      https://leetcode.com/problems/rotate-image/
 *
 *
 * Time: O(N^2)
 * Space: O(1)
 *
 *
 * Approach:
 * if we reverse engineer the output to input we will find that,
 * rotation = transpose + reverse rows
 *
 */

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
  // phase 1: initlization
  int i, j;
  int n = matrix.size();

  // phase 2: transpose of matrix
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // phase 3: reverse rows
  for (i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate(matrix);
  for (auto row : matrix) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "\n";
  }
  return 0;
}