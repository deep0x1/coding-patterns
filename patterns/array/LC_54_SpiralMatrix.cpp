/**
 *
 * Source:    LeetCode
 * Problem:   54. Spiral Matrix
 * Link:      https://leetcode.com/problems/spiral-matrix/description/
 *
 *
 * Approach 1:
 * peeling the onion style, use rect (top, righ, bottom, left)
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int row = matrix.size();
  int col = matrix[0].size();
  vector<int> sol;
  sol.reserve(row * col);

  int top = 0;
  int right = col - 1;
  int bottom = row - 1;
  int left = 0;

  while (top <= bottom && left <= right) {
    // left to right
    for (int j = left; j <= right; j++) {
      sol.push_back(matrix[top][j]);
    }
    top++;

    // top to bottom
    for (int i = top; i <= bottom; i++) {
      sol.push_back(matrix[i][right]);
    }
    right--;

    if (top <= bottom) {
      // right to left
      for (int j = right; j >= left; --j) {
        sol.push_back(matrix[bottom][j]);
      }
      bottom--;
    }

    if (left <= right) {
      // bottom to top
      for (int i = bottom; i >= top; --i) {
        sol.push_back(matrix[i][left]);
      }
      left++;
    }
  }

  return sol;
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> sol = spiralOrder(matrix);
  for (auto n : sol) {
    cout << n << ", ";
  }
  return 0;
}
