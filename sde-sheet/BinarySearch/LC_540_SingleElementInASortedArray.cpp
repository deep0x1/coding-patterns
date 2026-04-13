/**
 *
 * Source:    LC
 * Problem:   540. Single Element in a Sorted Array
 *
 *
 * Link:
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 *
 * Time: O(NLog(M))
 * Space: O(1)
 *
 *
 * Approach:
 * each pair starts with a even index, the pair index is broken then the single
 * element is on left else on right
 *
 */

#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
  int n = nums.size();

  if (n == 1) return nums[0];
  if (nums[0] != nums[1]) return nums[0];
  if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

  int low = 1;
  int high = n - 2;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    // base case
    if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
      return nums[mid];

    // choosing broken side
    if (mid % 2 == 0 && nums[mid] == nums[mid + 1] ||
        mid % 2 != 0 && nums[mid] == nums[mid - 1]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {1, 1, 2, 2, 4, 4, 5, 8, 8};
  cout << singleNonDuplicate(nums);
  return 0;
}