/**
 *
 * Source:    TOF
 * Problem:   Count the number of subarrays with given xor K
 *
 * Link:
 * https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k
 *
 *
 * Time: O(N)
 * Space: O(N)
 *
 *
 * Approach:
 * creating a hashmap to keep track of prefix xor and using concept of C = A ^ B
 * -> A = C ^ B to find target and if cost exists in the prefix xor we add it to
 * total subarrays
 *
 */

#include <bits/stdc++.h>

using namespace std;

int xorKSubarrays(vector<int>& nums, int k) {
  unordered_map<int, int> totalXOR;
  int currentXOR = 0;
  long long totalSubarrays = 0;

  totalXOR[currentXOR] = 1;
  for (auto n : nums) {
    currentXOR ^= n;
    int target = currentXOR ^ k;
    if (totalXOR.count(target)) totalSubarrays += totalXOR[target];
    totalXOR[currentXOR]++;
  }

  return totalSubarrays;
}

int main() {
  vector<int> nums = {5, 6, 7, 8, 9};
  int k = 5;
  cout << xorKSubarrays(nums, k);
  return 0;
}