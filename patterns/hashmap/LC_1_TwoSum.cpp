/**
 *
 * Source:    LeetCode
 * Problem:   1. Two Sum
 * Link:      https://leetcode.com/problems/two-sum/description/
 *
 *
 * Approach 1: OPTIMAL
 * create a unordered map and start looping though the array, calculate the cost
 * by subtracting the current element from target and check if that cost already
 * exist in the map, if it exist return current and stored index else add the
 * current index to the map
 *
 */

#include <bits/stdc++.h>
#define ARR_MAX 1000

using namespace std;

vector<int> solution(vector<int> nums, int target) {
  unordered_map<int, int> mpp;
  vector<int> sol;
  for (int i = 0; i < nums.size(); i++) {
    int cost = target - nums[i];
    unordered_map<int, int>::iterator it = mpp.find(cost);
    if (it != mpp.end() && (*it).second != i) {
      sol.push_back((*it).second);
      sol.push_back(i);
      return sol;
    }
    mpp.insert({nums[i], i});
  }
  return sol;
}

int main() {
  vector<int> nums = {3, 3};
  int target = 6;
  vector<int> result = solution(nums, target);
  cout << result[0] << ", " << result[1];
  return 0;
}