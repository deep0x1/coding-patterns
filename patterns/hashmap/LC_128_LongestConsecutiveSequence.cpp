/**
 *
 * Source:    LeetCode
 * Problem:   128. Longest Consecutive Sequence
 * Link:
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 *
 * Approach 1:
 * putting nums in an unordered_set and then looping throught it to find
 * sequence starters and if a sequence starter is found we just calculate the
 * sequence length and put it in a map
 *
 */

#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
  unordered_set<int> num_set(nums.begin(), nums.end());

  unordered_map<long, int> con_map;
  for (auto n : num_set) {
    long prev_num = n - 1;
    // check if its a sequence starter
    if (!num_set.count(prev_num)) {
      // count length of the sequence
      int curr_num = n;
      int length = 0;
      while (num_set.count(curr_num++)) length++;
      con_map[n] = length;
    }
  }

  int max_size = 0;
  for (const auto& pair : con_map) {
    max_size = max(max_size, pair.second);
  }

  return max_size;
}

int main() {
  vector<int> nums = {0, 0};
  int ans = longestConsecutive(nums);
  cout << ans;
  return 0;
}