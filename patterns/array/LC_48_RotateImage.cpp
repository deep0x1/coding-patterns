/**
 *
 * Source:    LeetCode
 * Problem:   48. Rotate Image
 * Link:      https://leetcode.com/problems/rotate-image/description/
 *
 *
 * Approach 1:
 * to rotate a matrix 90 deg we can transpose it and reverse all elements
 *
 */

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
  // transpose the array
  int n = matrix.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // reverse all rows
  for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate(matrix);
  for (auto row : matrix) {
    for (auto col : row) {
      cout << col << ", ";
    }
    cout << "\n";
  }
  return 0;
}
