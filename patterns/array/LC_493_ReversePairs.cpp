/**
 *
 * Source:    LeetCode
 * Problem:   493. Reverse Pairs
 * Link:      https://leetcode.com/problems/reverse-pairs/description/
 *
 *
 * Approach 1:
 * using two variables to calcualte max and min so far
 *
 */

#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) {
  if (nums.empty()) return 0;

  int max_so_far = nums[0];
  int min_so_far = nums[0];
  int result = max_so_far;
  for (int i = 1; i < nums.size(); i++) {
    int current = nums[i];
    int temp_max = max({current, current * max_so_far, current * min_so_far});
    min_so_far = min({current, current * max_so_far, current * min_so_far});
    max_so_far = temp_max;

    result = max(result, max_so_far);
  }
  return result;
}

int main() {
  vector<int> arr = {2, -5, -2, -4, 3};
  int ans = maxProduct(arr);
  cout << ans;
  return 0;
}