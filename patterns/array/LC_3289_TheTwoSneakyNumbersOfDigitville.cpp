/**
 *
 * Source:    LeetCode
 * Problem:   3289. The Two Sneaky Numbers of Digitville
 * Array Link:
 * https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
 *
 *
 * Approach 1: Optimal
 * using hashmap
 * worst case: O(N^2)
 * average case: O(N)
 *
 *
 * Approach 2:
 * using sorting
 * worst case: O(NlogN)
 * average case: O(NlogN)
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> getSneakyNumbersOptimal(vector<int>& nums) {
  unordered_map<int, int> n_map;
  for (auto n : nums) n_map[n]++;
  
  vector<int> result;
  for (auto pair : n_map) {
    if (pair.second > 1) {
      result.push_back(pair.first);
    }
  }
  return result;
}

vector<int> getSneakyNumbers(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  
  vector<int> result;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i-1]) {
      result.push_back(nums[i]);
    }
  }
  return result;
}

int main() {
  vector<int> nums = {7, 1, 5, 4, 3, 6, 6, 0, 9, 5, 8, 2};
  vector<int> ans = getSneakyNumbersOptimal(nums);
  cout << ans[0] << ", " << ans[1];
  return 0;
}