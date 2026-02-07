/**
 *
 * Source:    LeetCode
 * Problem:   74. Search a 2D Matrix

 * Link:
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 *
 * Time: O(Log(m) + Log(n)) = O(Log(mn))
 * Space: O(1)
 *
 *
 * Approach:
 * dual binary search, searching corret row and then searching correct col
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int low = 0;
  int high = matrix.size() - 1;
  int targetRow = low;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (matrix[mid][0] <= target) {
      targetRow = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  low = 0;
  high = matrix[targetRow].size() - 1;
  int targetCol = low;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (matrix[targetRow][mid] <= target) {
      targetCol = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return matrix[targetRow][targetCol] == target;
}

int main() {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 2;
  cout << searchMatrix(matrix, target);
  return 0;
}