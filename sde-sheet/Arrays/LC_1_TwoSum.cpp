/**
 *
 * Source:    LeetCode
 * Problem:   1. Two Sum
 *
 * Link:
 * https://leetcode.com/problems/two-sum/description/
 *
 *
 * Time: O(N)
 * Space: O(N)
 *
 *
 * Approach:
 * using hashmap to store the value and index and using it to check if required
 * difference was already stored
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> mpp;
  vector<int> sol(2);

  for (int i = 0; i < nums.size(); i++) {
    int cost = target - nums[i];
    unordered_map<int, int>::iterator it = mpp.find(cost);
    if (it != mpp.end() && it->second != i) {
      sol[0] = it->second;
      sol[1] = i;
      break;
    } else {
      mpp.insert({nums[i], i});
    }
  }

  return sol;
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  for (auto n : twoSum(nums, target)) cout << n << ", ";
  return 0;
}