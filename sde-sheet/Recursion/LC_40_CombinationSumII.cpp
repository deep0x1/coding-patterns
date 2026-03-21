/**
 *
 * Source:    LC
 * Problem:   40. Combination Sum II
 *
 *
 * Link:
 * https://leetcode.com/problems/combination-sum-ii/description/
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
               vector<int>& current_comb, vector<vector<int>>& all_comb) {
  if (target == 0) {
    all_comb.push_back(current_comb);
    return;
  }

  for (int i = idx; i < candidates.size(); i++) {
    if (i > idx && candidates[i] == candidates[i - 1]) continue;

    if (candidates[i] > target) {
      break;
    }

    current_comb.push_back(candidates[i]);
    backtrace(i + 1, target - candidates[i], candidates, current_comb,
              all_comb);
    current_comb.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  vector<vector<int>> all_comb;
  vector<int> current_comb;
  sort(candidates.begin(), candidates.end());
  backtrace(0, target, candidates, current_comb, all_comb);
  return all_comb;
}

int main() {
  vector<int> nums = {1, 1};
  int target = 1;
  vector<vector<int>> sol = combinationSum2(nums, target);
  for (auto r : sol) {
    for (auto c : r) cout << c << ", ";
    cout << "\n";
  }
  return 0;
}