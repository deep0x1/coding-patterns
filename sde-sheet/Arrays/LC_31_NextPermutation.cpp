/**
 *
 * Source:    LeetCode
 * Problem:   31. Next Permutation
 * Link:      https://leetcode.com/problems/next-permutation/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * initialize turningIdx and replacingIdx with -1
 * loop nums from (n - 1) to 0, looking for element smaller than next index
 * this index will be our turningIdx, now from (n) to turningIdx find element
 * bigger than turningIdx, this will be out replacingIdx
 * swap turningIdx with replacingIdx
 * reverse rest of array (turningIdx + 1 -> end)
 *
 */

#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {
  int i, j;
  int n = nums.size() - 1;
  int turningIdx = -1;
  int replacingIdx = -1;

  // phase 1: finding the turning index
  for (i = n - 1; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      turningIdx = i;
      break;
    }
  }

  if (turningIdx == -1) {
    // already at last permutation
    reverse(nums.begin(), nums.end());

  } else {
    // phase 2: find replacing index
    for (j = n; j > turningIdx; j--) {
      if (nums[j] > nums[turningIdx]) {
        replacingIdx = j;
        break;
      }
    }

    // swap turning index with replacing index
    swap(nums[turningIdx], nums[replacingIdx]);

    // sort the rest of elements by reversing them
    reverse(nums.begin() + turningIdx + 1, nums.end());
  }
}

int main() {
  vector<int> nums = {1, 3, 2};
  nextPermutation(nums);
  for (auto n : nums) cout << n << ", ";
  cout << "\n";
  return 0;
}