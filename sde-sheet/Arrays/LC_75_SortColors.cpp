/**
 *
 * Source:    LeetCode
 * Problem:   75. Sort Colors
 * Link:      https://leetcode.com/problems/sort-colors/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach: 
 * initilize three pivot (low, mid and high)
 * loop mid though the array
 * check for mid's value for 3 possible cases
 * case 1: mid is 0 -> swap mid with low and increment both
 * case 2: mid is 1 -> do nothing and increment mid
 * case 3: mid is 2 -> swap mid with high and decrement high only
 *
 */

#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
  // phase 1: initilization
  int n = nums.size();
  int low = 0;
  int mid = 0;
  int high = n - 1;

  // phase 2: looping mid thought nums
  while (mid <= high) {
    switch (nums[mid]) {
      case 0:
        swap(nums[mid], nums[low]);
        low++;
        mid++;
        break;

      case 2:
        swap(nums[mid], nums[high]);
        high--;
        break;

      case 1:
      default:
        mid++;
    }
  }
}

int main() {
  vector<int> nums = {2, 0, 1};
  sortColors(nums);
  for (auto num : nums) {
    cout << num << ", ";
  }
  return 0;
}