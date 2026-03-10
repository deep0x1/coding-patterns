/**
 *
 * Source:    LC
 * Problem:   26. Remove Duplicates from Sorted Array
 *
 *
 * Link:
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * using two pointer, second pointer only moves when we find a non duplicate
 * element
 *
 */

#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
  int n = nums.size();
  if (n <= 1) return n;

  int ptr = 1;
  for (int i = 1; i < n; i++) {
    if (nums[i] != nums[i - 1]) {
      nums[ptr] = nums[i];
      ptr++;
    }
  }

  return ptr;
}

int main() {
  vector<int> nums = {1, 1, 2};
  int k = removeDuplicates(nums);
  cout << k << endl;
  for (auto n : nums) cout << n << ", ";
  return 0;
}