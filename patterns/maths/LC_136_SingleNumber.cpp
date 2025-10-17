/**
 *
 * Source:    LeetCode
 * Problem:   136. Single Number
 * Link:
 * https://leetcode.com/problems/single-number/description/
 *
 *
 * Approach 1:
 * using hashmap
 *
 *
 * Approach 2:
 * using XOR (^)
 * XOR have few properties, three of them is:
 * (1) A ^ A = 0
 * (2) A ^ 0 = A
 * (3) order does not matter in XOR
 *
 * so that means if we do xor of all elements, every dublicate will cancel it
 * out while the single element remains
 *
 */

#include <bits/stdc++.h>

using namespace std;

// int singleNumber(vector<int>& nums) {
//   unordered_map<int, int> mpp;
//   for (auto num : nums) mpp[num]++;
//   for (auto it : mpp)
//     if (it.second == 1) return it.first;
// }

int singleNumber(vector<int>& nums) {
  int sol = 0;
  for (auto num : nums) sol ^= num;
  return sol;
}

int main() {
  vector<int> nums = {4, 1, 2, 1, 2};
  cout << singleNumber(nums);
  return 0;
}