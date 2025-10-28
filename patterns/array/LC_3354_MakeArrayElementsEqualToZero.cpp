/**
 *
 * Source:    LeetCode
 * Problem:   3354. Make Array Elements Equal to Zero
 * Link:
 * https://leetcode.com/problems/make-array-elements-equal-to-zero/description
 *
 *
 * Approach 1:
 * using prefix sum approach to find sum of elements on left and right, if both
 * left and right sum are same then we are on a valid place for both direction,
 * on other hand if there difference's absolute is 1, then out of two one
 * direction will be correct
 *
 */

#include <bits/stdc++.h>

using namespace std;

int countValidSelections(vector<int>& nums) {
  unordered_map<int, int> p_sum;
  vector<int> zeros;
  int n = nums.size();
  int crt_sum = 0;

  for (int i = 0; i < n; i++) {
    crt_sum += nums[i];
    p_sum[i] = crt_sum;
    if (nums[i] == 0) zeros.push_back(i);
  }

  int result = 0;
  for (auto z : zeros) {
    int left = p_sum[z];
    int right = crt_sum - left;
    int diff = abs(left - right);

    if (diff == 0)
      result += 2;
    else if (diff == 1)
      result++;
  }

  return result;
}

int countValidSelectionsOptimal(vector<int>& nums) {
  int n = nums.size();
  int total_sum = accumulate(nums.begin(), nums.end(), 0);
  int crt_sum = 0;
  int result = 0;
  for (auto z : nums) {
    crt_sum += z;
    if (z == 0) {
      int left_sum = crt_sum;
      int right_sum = total_sum - crt_sum;
      int diff = abs(left_sum - right_sum);

      if (diff == 0) result += 2;
      if (diff == 1) result += 1;
    }
  }
  return result;
}

int main() {
  vector<int> nums = {1, 0, 2, 0, 3};
  int ans = countValidSelectionsOptimal(nums);
  cout << ans;
  return 0;
}