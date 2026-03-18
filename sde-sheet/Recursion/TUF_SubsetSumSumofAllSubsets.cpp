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
 * Time: O(N^2)
 * Space: O(2^N)
 *
 *
 * Approach:
 * using bitmask approach, where we use 0 -> 2^n-1 numbers as mask and then only
 * add elements from nums which colide with mask (&)
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> findSubsetSum(vector<int> nums) {
  int n = nums.size();
  vector<int> subset_sum;

  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        sum += nums[i];
      }
    }
    subset_sum.push_back(sum);
  }

  sort(subset_sum.begin(), subset_sum.end());
  return subset_sum;
}

int main() {
  vector<int> nums = {5, 2, 1};
  vector<int> sol = findSubsetSum(nums);
  for (auto n : sol) cout << n << ", ";
  return 0;
}