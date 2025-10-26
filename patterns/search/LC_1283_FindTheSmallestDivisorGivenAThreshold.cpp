/**
 *
 * Source:    LeetCode
 * Problem:   1283. Find the Smallest Divisor Given a Threshold
 * Link:
 * https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
 *
 *
 * Approach 1:
 * using binary search approach on the range of possible solutions 1 to
 * max()
 *
 */

#include <bits/stdc++.h>

using namespace std;

int divisor_sum(vector<int>& nums, int divisor) {
  int result = 0;
  for (auto num : nums) {
    result += ceil((double)num / divisor);
  }
  return result;
}

int smallestDivisor(vector<int>& nums, int threshold) {
  int left = 1;
  int right = *max_element(nums.begin(), nums.end());
  int ans = left;

  while (left <= right) {
    int mid = (left + right) / 2;
    int cost = divisor_sum(nums, mid);

    if (cost <= threshold) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return ans;
}

int main() {
  int threshold = 1000000;
  vector<int> arr = {21212, 10101, 12121};
  int ans = smallestDivisor(arr, threshold);
  cout << ans;
  return 0;
}