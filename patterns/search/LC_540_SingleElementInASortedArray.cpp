/**
 *
 * Source:    LeetCode
 * Problem:   540. Single Element in a Sorted Array
 * Link:
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 *
 * Approach 1:
 * using modified binary search with logic of current element positioning,
 * (even, odd) and (odd, even)
 *
 */

#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) return nums[0];

  int left = 0;
  int right = n - 1;

  if (nums[left] != nums[left + 1]) return nums[left];
  if (nums[right] != nums[right - 1]) return nums[right];

  left++;
  right--;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
      return nums[mid];

    if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
        (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  vector<int> arr = {1, 1, 3, 3, 4, 5, 5, 8, 8};
  int ans = singleNonDuplicate(arr);
  cout << ans;
  return 0;
}