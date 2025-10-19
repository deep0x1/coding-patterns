/**
 *
 * Source:    LeetCode
 * Problem:   31. Next Permutation
 * Link:
 * https://leetcode.com/problems/next-permutation/description/
 *
 *
 * Approach 1:
 * Narayan Pandita Next Permutation Algorithm
 *
 */

#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
  // edge case
  int n = nums.size();
  if (n < 2) return;

  // finding pivot
  int pivot = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      pivot = i;
      break;
    }
  }

  // if no pivot found
  if (pivot == -1) {
    reverse(nums.begin(), nums.end());
    return;
  }
  
  // swap with succesor
  for (int i = n - 1; i > pivot; i--) {
    if (nums[i] > nums[pivot]) {
      swap(nums[i], nums[pivot]);
      break;
    }
  }

  // reverse the rest
  reverse(nums.begin() + pivot + 1, nums.end());
}

int main() {
  vector<int> nums = {1, 2, 3};
  nextPermutation(nums);
  for (auto n : nums) cout << n << ", ";
  return 0;
}