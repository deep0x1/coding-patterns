/**
 *
 * Source:    LeetCode
 * Problem:   34. Find First and Last Position of Element in Sorted Array
 * Link:      https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 *
 * Approach 1:
 * using binary search approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  // edge case
  if (nums.empty()) return {-1, -1};

  int n = nums.size() - 1;
  int left = 0;
  int right = n;
  int idx = -1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      idx = mid;
      break;
    }
  }

  // no result
  if (idx == -1) return {-1, -1};

  // if result
  left = right = idx;
  while (left >= 1 && nums[left - 1] == target) left--;
  while (right <= n - 1 && nums[right + 1] == target) right++;

  return {left, right};
}

int main() {
  int target = 1;
  vector<int> arr = {1};
  vector<int> ans = searchRange(arr, target);
  cout << ans[0] << ", " << ans[1];
  return 0;
}