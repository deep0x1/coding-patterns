/**
 *
 * Source:    LC
 * Problem:   485. Max Consecutive Ones
 *
 *
 * Link:
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * simple count and compare approach
 *
 */

#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
  int n = nums.size();
  int maxOnes = 0;
  int count = 0;

  for (auto n : nums) {
    if (n == 1)
      count++;
    else
      count = 0;
    maxOnes = max(maxOnes, count);
  }

  return maxOnes;
}

int main() {
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  int k = findMaxConsecutiveOnes(nums);
  cout << k << endl;
  return 0;
}