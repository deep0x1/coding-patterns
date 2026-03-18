/**
 *
 * Source:    TUF
 * Problem:   Subset Sum : Sum of all Subsets
 *
 *
 * Link:
 * https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets
 *
 *
 * Time: O(2^N)
 * Space: O(2^N)
 *
 *
 * Approach:
 * using recursive solve function to create binary branch, 1 where we add the
 * current sum, 1 where we don't
 *
 */

#include <bits/stdc++.h>

using namespace std;

void solve(int idx, vector<int>& nums, int sum, vector<int>& subset_sum) {
  if (idx >= nums.size()) {
    subset_sum.push_back(sum);
    return;
  }

  solve(idx + 1, nums, sum + nums[idx], subset_sum);
  solve(idx + 1, nums, sum, subset_sum);
}

vector<int> findSubsetSum(vector<int>& nums) {
  vector<int> subset_sum;
  solve(0, nums, 0, subset_sum);
  sort(subset_sum.begin(), subset_sum.end());
  return subset_sum;
}

int main() {
  vector<int> nums = {5, 2, 1};
  vector<int> sol = findSubsetSum(nums);
  for (auto n : sol) cout << n << ", ";
  return 0;
}