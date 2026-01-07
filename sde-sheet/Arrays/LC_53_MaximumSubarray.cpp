/**
 *
 * Source:    LeetCode
 * Problem:   53. Maximum Subarray
 * Link:      https://leetcode.com/problems/maximum-subarray/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * initilize totalSum (0) and maxSum (INT_MIN)
 * loop though the array of nums
 * add num to totalSum
 * compare maxSum with totalSum
 * if totalSum is negative reset it to 0 (as negative numbers will only decrease
 * the value furhter)
 *
 */

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
  // phase 1: initilization
  int totalSum = 0;
  int maxSum = INT_MIN;

  // phase 2: looping through array
  for (auto num : nums) {
    totalSum += num;
    maxSum = max(maxSum, totalSum);
    if (totalSum < 0) {
      totalSum = 0;
    }
  }

  return maxSum;
}

int main() {
  vector<int> nums = {1};
  cout << maxSubArray(nums) << "\n";
  return 0;
}