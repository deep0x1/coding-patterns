/**
 *
 * Source:    LeetCode
 * Problem:   56. Merge Intervals
 * Link:      https://leetcode.com/problems/merge-intervals
 *
 *
 * Time: O(NLogN)
 * Space: O(N)
 *
 *
 * Approach:
 * initlize output vector
 * sort the intervals array and insert first element to output
 * loop though intervals from i = 1 -> n and compare pairs with last output pair
 * and merge them based on condition
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  // phase 1: initilization
  int i;
  int n = intervals.size();
  vector<vector<int>> output;

  // phase 2: sort the intervals
  sort(intervals.begin(), intervals.end());

  // phase 3: insert first pair to output
  output.push_back(intervals[0]);

  // phase 4: merge pairs with output
  for (i = 1; i < n; i++) {
    vector<int>& currentVector = intervals[i];
    vector<int>& lastVector = output.back();

    if (lastVector[1] >= currentVector[0]) {
      lastVector[1] = max(lastVector[1], currentVector[1]);
    } else {
      output.push_back(currentVector);
    }
  }

  return output;
}

int main() {
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> output = merge(intervals);
  for (auto row : output) {
    for (auto col : row) {
      cout << col << ", ";
    }
    cout << "\n";
  }
  return 0;
}