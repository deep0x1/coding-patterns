/**
 *
 * Source:    LeetCode
 * Problem:   128. Longest Consecutive Sequence
 *
 * Link:
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 *
 * Time: O(N)
 * Space: O(N)
 *
 *
 * Approach:
 * creating set of unique numbers for O(1) lookup and loop through it to check
 * if number is first in series
 *
 */

#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  unordered_set<int> uniqueNums(nums.begin(), nums.end());
  int longest = 0;

  for (auto n : uniqueNums) {
    if (uniqueNums.count(n - 1)) continue;

    int length = 0;
    while (uniqueNums.count(n++)) length++;

    longest = max(longest, length);
  }

  return longest;
}

int main() {
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << longestConsecutive(nums);
  return 0;
}