/**
 *
 * Source:    LC
 * Problem:   46. Permutations
 *
 *
 * Link:
 * https://leetcode.com/problems/permutations/description/
 *
 *
 * Time: O(N^2)
 * Space: O(N)
 *
 *
 * Approach:
 * recursivling swaping index in nums to create different permutations
 *
 */

#include <bits/stdc++.h>

using namespace std;

void solve(int idx, vector<int>& nums, vector<vector<int>>& result) {
  if (idx == nums.size()) {
    result.push_back(nums);
    return;
  }

  for (int i = idx; i < nums.size(); i++) {
    swap(nums[idx], nums[i]);
    solve(idx + 1, nums, result);
    swap(nums[idx], nums[i]);
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> result;
  solve(0, nums, result);
  return result;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> perm = permute(nums);
  for (auto row : perm) {
    for (auto col : row) cout << col << "\t";
    cout << endl;
  }
  return 0;
}