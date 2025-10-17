/**
 *
 * Source:    LeetCode
 * Problem:   485. Max Consecutive Ones
 * Link:
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 *
 * Approach 1:
 * two variable approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
  int count = 0;
  int temp = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 1) {
      temp++;
    } else {
      temp = 0;
    }
    count = max(temp, count);
  }
  return count;
}

int main() {
  vector<int> nums = {0};
  cout << findMaxConsecutiveOnes(nums);
  return 0;
}