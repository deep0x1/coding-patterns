/**
 *
 * Source:    TUF
 * Problem:   Median of Row Wise Sorted Matrix
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix
 *
 *
 * Time: O(NLog(M))
 * Space: O(1)
 *
 *
 * Approach:
 * using binary search between lowest and hightest element in the matrix and
 * then thresholding untill the search ends with no new possible solution and
 * then using last found solution as result
 *
 */

#include <bits/stdc++.h>

using namespace std;

int find_median(vector<vector<int>>& matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int req = (n * m) / 2;
  int median = -1;

  int low = matrix[0][0];
  int high = matrix[0][0];

  for (int i = 0; i < n; i++) {
    low = min(low, matrix[i][0]);
    high = max(high, matrix[i][m - 1]);
  }

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int count = 0;

    for (int i = 0; i < n; i++) {
      auto it = upper_bound(matrix[i].begin(), matrix[i].end(), mid);
      count += it - matrix[i].begin();
    }

    if (count > req) {
      median = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return median;
}

int main() {
  vector<vector<int>> matrix = {{1, 4, 9}, {2, 5, 6}, {3, 8, 7}};
  cout << find_median(matrix);
  return 0;
}