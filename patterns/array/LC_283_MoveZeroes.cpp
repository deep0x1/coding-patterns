/**
 *
 * Source:    LeetCode
 * Problem:   283. Move Zeroes
 * Link:
 * https://leetcode.com/problems/move-zeroes/description/
 *
 *
 * Approach 1:
 * use two pointer approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
  int i = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (nums[j] != 0) {
      nums[i] = nums[j];
      i++;
    }
  }
  for (; i < nums.size(); i++) {
    nums[i] = 0;
  }
}

int main() {
  int k = 3;
  vector<int> nums = {0};
  moveZeroes(nums);
  for (auto n : nums) cout << n << ", ";
  return 0;
}