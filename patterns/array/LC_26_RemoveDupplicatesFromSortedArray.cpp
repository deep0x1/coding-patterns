/**
 *
 * Source:    LeetCode
 * Problem:   26. Remove Duplicates from Sorted Array
 * Link:
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 *
 * Approach 1:
 * use two pointer approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
  if (nums.empty()) return 0;
  int i = 1;
  for (int j = 1; j < nums.size(); j++) {
    if (nums[j] != nums[i - 1]) {
      nums[i] = nums[j];
      i++;
    }
  }
  return i;
}

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k = removeDuplicates(nums);
  cout << k << "\n";
  for (auto n : nums) cout << n << ", ";
  return 0;
}