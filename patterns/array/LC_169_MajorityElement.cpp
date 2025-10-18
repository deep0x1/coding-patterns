/**
 *
 * Source:    LeetCode
 * Problem:   169. Majority Element
 * Link:      https://leetcode.com/problems/majority-element/description/
 *
 *
 * Approach 1:
 * using hashmap
 *
 *
 * Approach 2: Optimal
 * Boyer-Moore Voting Algorithm
 *
 */

#include <bits/stdc++.h>

using namespace std;

int majorityElement(vector<int>& nums) {
  unordered_map<int, int> counts;
  for (auto n : nums) counts[n]++;

  int target = nums[0];
  int target_count = 0;
  for (auto it : counts) {
    if (it.second > target_count) {
      target = it.first;
      target_count = it.second;
    }
  }
  return target;
}

int majorityElementOptimal(vector<int>& nums) {
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
  vector<int> arr = {1, 1, 1, 3, 2, 3, 4, 4, 2, 4, 4, 4, 4, 4};
  int sol = majorityElementOptimal(arr);
  cout << sol;
  return 0;
}