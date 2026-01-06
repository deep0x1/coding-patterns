/**
 *
 * Source:    LeetCode
 * Problem:   118. Pascal's Triangle
 * Link:      https://leetcode.com/problems/pascals-triangle/description/
 *
 *
 * Time: O(N^2)
 * Space: O(N^2)
 *
 *
 * Approach:
 * create a empty 2d vector triangle
 * loop i from 0 to n
 * create row of size (i + 1) and init with 1
 * fill row using last last row
 * push row to triangle
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
  // phase 1: initialize the triangle
  vector<vector<int>> triangle;
  int i, j;

  // phase 2: create rows
  for (i = 0; i < numRows; i++) {
    vector<int> row(i + 1, 1);

    for (j = 1; j < i; j++) {
      row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
    }

    triangle.push_back(row);
  }

  return triangle;
}

int main() {
  int numRows = 5;
  vector<vector<int>> triangle = generate(numRows);
  for (auto row : triangle) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "\n";
  }
}