/**
 *
 * Source:    LeetCode
 * Problem:   189. Rotate Array
 * Link:
 * https://leetcode.com/problems/rotate-array/description/
 *
 *
 * Approach 1:
 * Take the array (k = 3)
 * [1, 2, 3, 4, 5, 6, 7]
 * 
 * Reverse the array (k = 3)
 * [7, 6, 5, 4, 3, 2, 1]
 * 
 * Reverse the array before `K or K % size`
 * [5, 6, 7, 4, 3, 2, 1]
 * 
 * Reverse the rest of array 
 * [5, 6, 7, 1, 2, 3, 4] SOL
 *
 */

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k) {
  int size = nums.size();

  k = k % size;
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

int main() {
  int k = 3;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  rotate(nums, k);
  for (auto n : nums) cout << n << ", ";
  return 0;
}