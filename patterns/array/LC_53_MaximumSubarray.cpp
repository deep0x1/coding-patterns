/**
 *
 * Source:    LeetCode
 * Problem:   53. Maximum Subarray
 * Link:      https://leetcode.com/problems/maximum-subarray/description/
 *
 *
 * Approach 1: OPTIMAL
 * Kedane's algorithm
 *
 */

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
  int w_sum = 0;
  int g_sum = INT_MIN;

  for (int i = 0; i < nums.size(); i++) {
    w_sum += nums[i];
    g_sum = max(g_sum, w_sum);
    if (w_sum < 0) w_sum = 0;
  }

  return g_sum;
}

int main() {
  vector<int> arr = {5, 4, -1, 7, 8};
  int sol = maxSubArray(arr);
  cout << sol;
  return 0;
}