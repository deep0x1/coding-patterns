/**
 *
 * Source:    LeetCode
 * Problem:   153. Find Minimum in Rotated Sorted Array
 * Link:
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 *
 * Approach 1:
 * using modified binary search, where we check which side is sorted and then we
 * compare the most left element of the sorted part and elemenates that part of
 * array
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums) {
  int b_min = INT_MAX;
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    cout << "MIN: " << b_min << "\t[ " << nums[left] << ", " << nums[right]
         << " ]\n";

    if (nums[left] <= nums[mid]) {
      b_min = min(b_min, nums[left]);
      left = mid + 1;
    } else {
      b_min = min(b_min, nums[mid]);
      right = mid - 1;
    }
  }

  return b_min;
}

int main() {
  vector<int> arr = {6, 7, 1, 2, 3, 4, 5};
  bool ans = findMin(arr);
  cout << ans;
  return 0;
}