/**
 *
 * Source:    LeetCode
 * Problem:   229. Majority Element II
 *
 * Link:
 * https://leetcode.com/problems/majority-element-ii/description/
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

vector<int> majorityElement(vector<int>& nums) {
  int target1 = INT_MAX;
  int target2 = INT_MAX;
  int count1 = 0;
  int count2 = 0;

  // phase 1: finding possible targets
  for (auto n : nums) {
    if (n == target1) {
      count1++;
    } else if (n == target2) {
      count2++;
    } else if (count1 == 0) {
      target1 = n;
      count1 = 1;
    } else if (count2 == 0) {
      target2 = n;
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }

  // phase 2: finding actual count
  count1 = 0;
  count2 = 0;
  for (auto n : nums) {
    if (n == target1)
    count1++;
    else if (n == target2)
    count2++;
  }
  
  // phase 3: creating result
  vector<int> result;
  int threshold = nums.size() / 3;
  if (count1 > threshold) {
    result.push_back(target1);
  }
  if (count2 > threshold) {
    result.push_back(target2);
  }

  return result;
}

int main() {
  vector<int> nums = {1, 2};
  vector<int> sol = majorityElement(nums);
  for (auto n : sol) cout << n << ", ";
  return 0;
}