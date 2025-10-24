/**
 *
 * Source:    LeetCode
 * Problem:   33. Search in Rotated Sorted Array
 * Link:
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 *
 * Approach 1:
 * using modified binary search, where we check which side is sorted
 *
 */

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int ans = -1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid] == target) {
      ans = mid;
      break;
    }

    if (nums[left] <= nums[mid]) {
      if (nums[left] <= target && target <= nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (nums[mid] <= target && target <= nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  return ans;
}

int main() {
  int target = 9;
  vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
  // vector<int> arr = {0, 1, 2, 4, 5, 6, 7};
  int ans = search(arr, target);
  cout << ans;
  return 0;
}