/**
 *
 * Source:    LeetCode
 * Problem:   169. Majority Element
 *
 * Link:
 * https://leetcode.com/problems/majority-element/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * we are using boyer-moore majority voting algorithm
 *
 */

#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int>& nums) {
  int target = nums[0];
  int count = 0;

  for (auto n : nums) {
    if (count == 0) target = n;
    if (target == n)
      count++;
    else
      count--;
  }

  return target;
}

int main() {
  vector<int> nums = {3, 2, 3};
  cout << majorityElement(nums);
  return 0;
}