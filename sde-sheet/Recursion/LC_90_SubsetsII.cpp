/**
 *
 * Source:    LC
 * Problem:   90. Subsets II
 *
 *
 * Link:
 * https://leetcode.com/problems/subsets-ii/description/
 *
 *
 * Time: O(2^N)
 * Space: O(2^N)
 *
 *
 * Approach:
 * using recursive for loop backtrace approach, all nodes in the backtrace are
 * valid subsets
 *
 */

#include <bits/stdc++.h>

using namespace std;

void backtrace(int index, vector<int>& nums, vector<int>& current_subset,
               vector<vector<int>>& all_subset) {
  all_subset.push_back(current_subset);

  for (int i = index; i < nums.size(); i++) {
    if (i > index && nums[i] == nums[i - 1]) continue;

    current_subset.push_back(nums[i]);
    backtrace(i + 1, nums, current_subset, all_subset);
    current_subset.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> all_subset;
  vector<int> current_subset;

  sort(nums.begin(), nums.end());
  backtrace(0, nums, current_subset, all_subset);

  return all_subset;
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  vector<vector<int>> sol = subsetsWithDup(nums);
  for (auto r : sol) {
    for (auto c : r) cout << c << ", ";
    cout << "\n";
  }
  return 0;
}