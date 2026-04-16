/**
 *
 * Source:    LC
 * Problem:   33. Search in Rotated Sorted Array
 *
 *
 * Link:
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 *
 * Time: O(Log(N))
 * Space: O(1)
 *
 *
 * Approach:
 * property of rotated sorted array is that if we split it from any mid, one
 * side of the array will always be sorted, using this property we can do a
 * binary search and check if target is in the sorted side, if it is then we
 * further search it or search the other side
 *
 */

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
  int n = nums.size();
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;

    // check if left half is sorted
    if (nums[low] <= nums[mid]) {
      if (nums[low] <= target && target <= nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    // other wise right half is sorted
    else {
      if (nums[mid] <= target && target <= nums[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }

  return -1;
}

int main() {
  int target = 5;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << search(nums, target);
  return 0;
}