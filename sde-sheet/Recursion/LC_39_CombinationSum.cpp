/**
 *
 * Source:    LC
 * Problem:   39. Combination Sum
 *
 *
 * Link:
 * https://leetcode.com/problems/combination-sum/description/
 *
 *
 * Time: O(2^N)
 * Space: O(2^N)
 *
 *
 * Approach:
 * using recursive for loop backtrace approach, all nodes in the backtrace are
 * checked if they create a combination
 *
 */

#include <bits/stdc++.h>

using namespace std;

void backtrace(int idx, int target, vector<int>& candidates,
               vector<int>& current_combo, vector<vector<int>>& all_comb) {
  if (target == 0) {
    all_comb.push_back(current_combo);
    return;
  }

  for (int i = idx; i < candidates.size(); i++) {
    if (candidates[i] > target) {
      break;
    }

    current_combo.push_back(candidates[i]);
    backtrace(i, target - candidates[i], candidates, current_combo, all_comb);
    current_combo.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> all_comb;
  vector<int> current_comb;
  sort(candidates.begin(), candidates.end());
  backtrace(0, target, candidates, current_comb, all_comb);
  return all_comb;
}

int main() {
  vector<int> nums = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> sol = combinationSum(nums, target);
  for (auto r : sol) {
    for (auto c : r) cout << c << ", ";
    cout << "\n";
  }
  return 0;
}