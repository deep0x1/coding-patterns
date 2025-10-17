/**
 *
 * Source:    LeetCode
 * Problem:   1752. Check if Array Is Sorted and Rotated
 * Link:
 * https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 *
 *
 * Approach 1:
 * Initialize flag with false, and now look for break point and change flag to
 * true, after break point if another breakpoint found, return false, else check
 * if first element greater or equal to last if breakpoint was found, if not
 * then return true
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& nums) {
  bool flag = false;
  int i;
  for (i = 0; i < nums.size() - 1; i++) {
    if (flag) {
      if (nums[i] > nums[i + 1]) return false;
    } else {
      if (nums[i] > nums[i + 1]) flag = true;
    }
  }
  if (flag) {
    return nums[0] >= nums[i];
  } else {
    return true;
  }
}

int main() {
  vector<int> nums = {6, 10, 6};
  cout << check(nums);
  return 0;
}