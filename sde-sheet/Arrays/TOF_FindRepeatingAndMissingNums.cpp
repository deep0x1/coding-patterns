/**
 *
 * Source:    TOF
 * Problem:   Find the repeating and missing numbers
 * Link:      https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers
 *
 *
 * Time: O(N)
 * Space: O(1)
 *
 *
 * Approach:
 * using xor property [a ^ 0 = a] and [a ^ a = 0] to find xor of missing and
 * repeated number, then using right most set bit to seprate both
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> findMissing(vector<int>& nums) {
  // phase 1: initilization
  int i;
  int n = nums.size();
  unordered_map<int, int> mp;

  // phase 2: creating map
  for (auto n : nums) mp[n]++;

  // phase 3: finding missing
  int missing = 0;
  int repeating = 0;
  for (i = 1; i <= n; i++) {
    if (mp[i] == 0) {
      missing = i;
    }
    if (mp[i] > 1) {
      repeating = i;
    }
  }

  return {repeating, missing};
}

vector<int> findMissingOptimal(vector<int>& nums) {
  // phase 1: initilization
  int xr = 0;
  int i, diff_bit, b0, b1;
  int n = nums.size();
  
  // phase 2: xor
  for (i = 0; i < n; i++) {
    xr ^= nums[i] ^ (i + 1);  // xr = Arr ^ N
  }

  // phase 3: find right set bit
  diff_bit = xr & ~(xr - 1);

  // phase 4: seprating A and B from xr
  b0 = 0;
  b1 = 0;
  for (i = 0; i < n; i++) {
    if ((nums[i] & diff_bit) == 0)
      b0 ^= nums[i];
    else
      b1 ^= nums[i];

    if (((i + 1) & diff_bit) == 0)
      b0 ^= (i + 1);
    else
      b1 ^= (i + 1);
  }

  // phase 5: check repeat and missing
  for (i = 0; i < n; i++) {
    if (nums[i] == b0) {
      return {b0, b1};
    }
  }

  return {b1, b0};
}

int main() {
  vector<int> nums = {1, 2, 3, 6, 7, 5, 7};
  vector<int> sol = findMissingOptimal(nums);
  cout << sol[0] << ", " << sol[1];
  return 0;
}