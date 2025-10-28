/**
 *
 * Source:    LeetCode
 * Problem:   410. Split Array Largest Sum
 * Link:
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 *
 * Approach 1:
 * binary search on answer, where range of ans is [max(), sum()]
 *
 */

#include <bits/stdc++.h>

using namespace std;

int count_subarray(vector<int>& nums, int max_sum) {
  int total_subarray = 1;
  int crt_sum = 0;
  for (auto n : nums) {
    if (crt_sum + n > max_sum) {
      total_subarray++;
      crt_sum = n;
    } else {
      crt_sum += n;
    }
  }
  return total_subarray;
}

int splitArray(vector<int>& nums, int k) {
  int left = *max_element(nums.begin(), nums.end());
  int right = accumulate(nums.begin(), nums.end(), 0);

  while (left <= right) {
    int mid = left + (right - left) / 2;
    int cost = count_subarray(nums, mid);
    if (cost > k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return left;
}

int main() {
  int k = 3;
  vector<int> nums = {1, 4, 4};
  // int ans = count_subarray(nums, 15);
  int ans = splitArray(nums, k);
  cout << ans;
  return 0;
}