/**
 *
 * Source:    LeetCode
 * Problem:   73. Set Matrix Zeroes
 * Link:      https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 *
 * Approach 1:
 * using unordered map for rows and columns
 *
 */

#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  unordered_map<int, int> row;
  unordered_map<int, int> col;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] == 0) {
        row[i]++;
        col[j]++;
      }
    }
  }

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (row[i] > 0 || col[j] > 0) {
        matrix[i][j] = 0;
      }
    }
  }
}

int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  setZeroes(matrix);
  for (auto row : matrix) {
    for (auto col : row) {
      cout << col << ", ";
    }
    cout << "\n";
  }
  return 0;
}
