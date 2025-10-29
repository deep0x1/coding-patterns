/**
 *
 * Source:    LeetCode
 * Problem:   3370. Smallest Number With All Set Bits
 * Link:
 * https://leetcode.com/problems/smallest-number-with-all-set-bits/description
 *
 *
 * Approach 1:
 * using `floor(log2(n)) + 1` to find total number of used bits in a number and
 * then using bit shifting technique to generate a number with `n` set bits
 *
 */

#include <bits/stdc++.h>

using namespace std;

int smallestNumber(int n) {
  int total_bits = floor(log2(n)) + 1;
  // int result = 0;
  // for (int i = 0; i < total_bits; i++) {
  //   result = (result << 1) | 1;
  // }
  int result = 1;
  result = (result << total_bits) - 1;
  return result;
}

int main() {
  int n = 1;
  int ans = smallestNumber(n);
  cout << ans;
  return 0;
}