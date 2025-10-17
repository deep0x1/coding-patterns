/**
 *
 * Source:    TUF
 * Problem:   Longest Subarray with given Sum K(Positives)
 * Link:
 * https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/
 *
 *
 * Approach 1:
 * using sliding window
 *
 */

#include <bits/stdc++.h>

using namespace std;

int longest_subarray(vector<int>& nums, int k) {
  int max_len = 0;
  int w_sum = 0;
  int w_left = 0;
  int w_right = 0;

  for (w_right = 0; w_right < nums.size(); w_right++) {
    w_sum += nums[w_right];

    while (w_sum > k) {
      w_sum -= nums[w_left];
      w_left++;
    }

    if (w_sum == k) {
      max_len = max(max_len, w_right - w_left);
    }
  }

  return max_len;
}

int main() {
  int k = 1;
  vector<int> nums = {-1, 1, 1};
  cout << longest_subarray(nums, k);
  return 0;
}