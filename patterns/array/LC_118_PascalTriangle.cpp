/**
 *
 * Source:    LeetCode
 * Problem:   118. Pascal's Triangle
 * Link:      https://leetcode.com/problems/pascals-triangle/description/
 *
 *
 * Approach 1:
 * using arthematics
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> result = {};
  for (int i = 0; i < numRows; i++) {
    result.push_back({});
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        result[i].push_back(1);
        continue;
      }
      int sum = result[i - 1][j - 1] + result[i - 1][j];
      result[i].push_back(sum);
    }
  }
  return result;
}

int main() {
  int k = 0;
  vector<vector<int>> sol = generate(k);
  for (auto row : sol) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << "\n";
  }
  return 0;
}
