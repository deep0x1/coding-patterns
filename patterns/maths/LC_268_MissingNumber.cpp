/**
 *
 * Source:    LeetCode
 * Problem:   268. Missing Number
 * Link:
 * https://leetcode.com/problems/missing-number/description/
 *
 *
 * Approach 1:
 * calculate sum of array and subtract it by n * (n + 1) / 2
 *
 */

#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
  int size = nums.size();
  long long total = (size * (size + 1)) / 2;
  long long sum = 0;
  for (auto num: nums) sum += num;
  return (int)(total - sum);
}

int main() {
  vector<int> nums = {3,0,1};
  cout << missingNumber(nums);
  return 0;
}