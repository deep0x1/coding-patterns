/**
 *
 * Source:    LeetCode
 * Problem:   81. Search in Rotated Sorted Array II
 * Link:
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 *
 * Approach 1:
 * using modified binary search, where we check which side is sorted and to handle dublicates we are shrinking our array if our left, mid and right are same
 *
 */

#include <bits/stdc++.h>

using namespace std;

bool search(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  bool ans = false;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid] == target) {
      ans = true;
      break;
    }

    if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
      left++;
      right--;
    } else if (nums[left] <= nums[mid]) {
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
  int target = 2;
  vector<int> arr = {3, 1, 2, 3, 3 ,3, 3};
  bool ans = search(arr, target);
  cout << ans;
  return 0;
}