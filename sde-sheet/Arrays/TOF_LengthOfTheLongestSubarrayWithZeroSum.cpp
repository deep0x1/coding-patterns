/**
 *
 * Source:    TOF
 * Problem:   Length of the longest subarray with zero Sum
 *
 * Link:
 * https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum
 *
 *
 * Time: O(N)
 * Space: O(N)
 *
 *
 * Approach:
 * creating a hashmap to keep track of prefix sum and if we find a sum twice
 * that means we have 0 sum subarray in between two index
 *
 */

#include <bits/stdc++.h>

using namespace std;

int longestSubarraySum(vector<int>& nums) {
  unordered_map<int, int> totalSum;
  int n = nums.size();
  int currentSum = 0;
  int longestSubarray = 0;

  totalSum[currentSum] = -1;
  for (int i = 0; i < n; i++) {
    currentSum += nums[i];

    if (totalSum.count(currentSum)) {
      int length = i - totalSum[currentSum];
      longestSubarray = max(longestSubarray, length);
    } else {
      totalSum[currentSum] = i;
    }
  }

  return longestSubarray;
}

int main() {
  vector<int> nums = {9, -3, 3, -1, 6, -5};
  cout << longestSubarraySum(nums);
  return 0;
}