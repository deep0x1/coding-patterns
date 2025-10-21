/**
 *
 * Source:    LeetCode
 * Problem:   56. Merge Intervals
 * Link:      https://leetcode.com/problems/merge-intervals/description/
 *
 *
 * Approach 1:
 * sorting and comparing y
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  // sort array
  sort(intervals.begin(), intervals.end(),
       [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

  vector<vector<int>> ans;
  ans.push_back(intervals[0]);

  for (int i = 1; i < intervals.size(); i++) {
    vector<int> curr = intervals[i];

    if (ans.back()[1] >= intervals[i][0]) {
      ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    } else {
      ans.push_back(curr);
    }
  }

  return ans;
}

int main() {
  int k = 5;
  vector<vector<int>> arr = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
  vector<vector<int>> ans = merge(arr);
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << ", ";
    }
    cout << "\n";
  }
  return 0;
}
