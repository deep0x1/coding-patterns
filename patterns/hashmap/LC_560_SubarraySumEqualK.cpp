/**
 *
 * Source:    LeetCode
 * Problem:   560. Subarray Sum Equals K
 * Link:      https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 *
 * Approach 1: optimal
 * prefix sum approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> sum_map;
  int count = 0;
  int current_sum = 0;

  sum_map[0] = 1;
  for (auto n : nums) {
    current_sum += n;
    if (sum_map.count(current_sum - k)) {
      count += sum_map[current_sum - k];
    }
    sum_map[current_sum]++;
  }

  return count;
}

int main() {
  int k = 0;
  vector<int> nums = {-1, -1, 1};
  int sol = subarraySum(nums, k);
  cout << sol;
  return 0;
}
