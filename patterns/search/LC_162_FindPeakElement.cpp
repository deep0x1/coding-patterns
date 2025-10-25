/**
 *
 * Source:    LeetCode
 * Problem:   162. Find Peak Element
 * Link:
 * https://leetcode.com/problems/find-peak-element/description/
 *
 *
 * Approach 1:
 * using modified binary search where we will compare the mid element with
 * adgecent elements and element the shorter side of array with assumption of
 * greater element may be the peak element
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int>& nums) {
  // edge case
  if (nums.size() == 1) return 0;

  int left = 0;
  int right = nums.size() - 1;

  if (nums[left] > nums[left + 1]) return left;
  if (nums[right] > nums[right - 1]) return right;

  left++;
  right--;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) return mid;

    if (nums[mid - 1] > nums[mid]) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

int main() {
  vector<int> arr = {1, 2};
  int ans = findPeakElement(arr);
  cout << ans;
  return 0;
}